#ifndef LED_H_
#define LED_H_

#include "debounce.h"

#define NUM_BUTTONS  6

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} sLedColor;

typedef struct {
  ePinId pinId;
  uint8_t led1;
  uint8_t led2;
  sLedColor color_on;
  sLedColor color_off;
} sButtonRef;

static sButtonRef buttons[NUM_BUTTONS] =
{
  {
    .pinId = BT_A,
    .led1 = 3,
    .led2 = 4,
    .color_on = {0, 0, 255},
    .color_off = {100, 100, 100}
  },
  {
    .pinId = BT_B,
    .led1 = 2,
    .led2 = 5,
    .color_on = {0, 0, 255},
    .color_off = {100, 100, 100}
  },
  {
    .pinId = BT_C,
    .led1 = 1,
    .led2 = 6,
    .color_on = {0, 0, 255},
    .color_off = {100, 100, 100}
  },
  {
    .pinId = BT_D,
    .led1 = 0,
    .led2 = 7,
    .color_on = {0, 0, 255},
    .color_off = {100, 100, 100}
  },
  {
    .pinId = FX_L,
    .led1 = 9,
    .led2 = 10,
    .color_on = {255, 0, 0},
    .color_off = {100, 100, 100}
  },
  {
    .pinId = FX_R,
    .led1 = 8,
    .led2 = 11,
    .color_on = {255, 0, 0},
    .color_off = {100, 100, 100}
  }
};  


void UpdateLeds(void);

#endif /* LED_H_ */