#include "led.h"
#include "debounce.h"
#include "neopixel.h"

void UpdateLeds(void)
{
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (DebounceGetLevel(buttons[i].pinId)) {
      NeoPixelSetPixelColor(buttons[i].led1, buttons[i].color_off.r, buttons[i].color_off.g, buttons[i].color_off.b);
      NeoPixelSetPixelColor(buttons[i].led2, buttons[i].color_off.r, buttons[i].color_off.g, buttons[i].color_off.b);
    } else {
      NeoPixelSetPixelColor(buttons[i].led1, buttons[i].color_on.r, buttons[i].color_on.g, buttons[i].color_on.b);
      NeoPixelSetPixelColor(buttons[i].led2, buttons[i].color_on.r, buttons[i].color_on.g, buttons[i].color_on.b);
    }
  }
}