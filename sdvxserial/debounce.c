#include "debounce.h"

void DebounceInit(void)
{
  /* Setup Debounce Timer */
  TCCR0A |= (1 << COM0A1) | (1 << COM0A0); // Set OC0A on compare
  TCNT0 = 0; // Reset timer count
  OCR0A = 0xFF; // Compare value
  TIFR0 = (1 << OCF0A); // Clear compare flag
  TCCR0B |= (1 << CS02) | (1 << CS00); // Select clock : 1024 prescale div
  /* 16 MHz / 1024 = 15.625 kHz -> 64 us per tick -> 15.63 ticks per ms */
}

void DebounceUpdate(void)
{
  sPinRef *pr;
  if (TIFR0 & (1 << OCF0A)) {
    for (ePinId p = 0; p < BT_A/*NUM_PINS*/; p++) {
      pr = &pins[p];
      if (pr->level != (bool) (pr->mask & *(pr->port))) {
        pr->count++;
        if (pr->count > DEBOUNCE_TRIGGER_COUNT) {
          pr->level = !pr->level;
          pr->count = 0;
        }
      } else {
        pr->count = 0;
      }
    }
    TIFR0 = (1 << OCF0A);
  }
}

bool DebounceGetLevel(ePinId id)
{
  return pins[id].level;
}