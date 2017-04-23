#if 0
typedef enum {
  ENC_LEFT_A = 0,
  ENC_LEFT_B,
  ENC_RIGHT_A,
  ENC_RIGHT_B,
  BT_A,
  BT_B,
  BT_C,
  BT_D,
  FX_L,
  FX_R,
  START,
  NUM_PINS
} ePinId;

typedef struct {
  uint8_t count;
  bool level;
  uint8_t mask;
  uint8_t *port;
} sPinRef;

sPinRef pins[NUM_PINS] =
{
  {
    /* ENC_LEFT_A */
    .count = 0;
    .level = 0;
    .mask = (1 << 7);
    .port = &PINB;
  },
  {
    /* ENC_LEFT_B */
    .count = 0;
    .level = 0;
    .mask = (1 << 0);
    .port = &PINB;
  },  
}

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
#define DEBOUNCE_TRIGGER_COUNT 20
void DebounceUpdate(void)
{
  sPinRef *pr;
  if (TIFR0 & (1 << OCF0A)) {
    for (ePinId p = 0; p < NUM_PINS; p++) {
      pr = &pins[p];
      if (pr->level != (bool) (pr->mask & *(pr->port)) {
        pr->count++;
        if (pr->count > DEBOUNCE_TRIGGER_COUNT) {
          pr->level = !pr->level;
          pr->count = 0;
        }
      } else {
        pr->count = 0;
      }
    }
    TIFR0 = (1 << 0CF0A);
  }
}
#endif