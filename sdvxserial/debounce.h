#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include "debounce.h"
#include <stddef.h>
#include <stdbool.h>
#include <avr/io.h>

#define DEBOUNCE_TIMER_COMPARE_COUNT 8
#define DEBOUNCE_TRIGGER_COUNT 30

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
  const uint8_t mask;
  const volatile uint8_t *port;
} sPinRef;

static sPinRef pins[NUM_PINS] =
{
  {
    /* ENC_LEFT_A */
    .count = 0,
    .level = 0,
    .mask = (1 << 5),
    .port = &PINB
  },
  {
    /* ENC_LEFT_B */
    .count = 0,
    .level = 0,
    .mask = (1 << 6),
    .port = &PINB
  },
  {
    /* ENC_RIGHT_A */
    .count = 0,
    .level = 0,
    .mask = (1 << 7),
    .port = &PINB
  },
  {
    /* ENC_RIGHT_B */
    .count = 0,
    .level = 0,
    .mask = (1 << 0),
    .port = &PINB
  },
};

void DebounceInit(void);
void DebounceUpdate(void);
bool DebounceGetLevel(ePinId id);

#endif /* DEBOUNCE_H_ */