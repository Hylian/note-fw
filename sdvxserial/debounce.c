#include "debounce.h"

void DebounceInit(void)
{
  /* Setup Debounce Timer */
  TCCR0A |= (1 << COM0A1) | (1 << COM0A0); // Set OC0A on compare
  TCNT0 = 0; // Reset timer count
  OCR0A = DEBOUNCE_TIMER_COMPARE_COUNT; // Compare value
  TIFR0 = (1 << OCF0A); // Clear compare flag
  TCCR0B |= (1 << CS01) | (1 << CS00); // Select clock : 64 prescale div -> 250 kHz
}

void DebounceUpdate(void)
{
  sPinRef *pr;
  if (TIFR0 & (1 << OCF0A)) {
    for (ePinId p = 0; p < NUM_PINS; p++) {
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
    TCNT0 = 0;
  }
}

bool DebounceGetLevel(ePinId id)
{
  return pins[id].level;
}