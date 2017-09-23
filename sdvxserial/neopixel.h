#ifndef NEOPIXEL_H_
#define NEOPIXEL_H_

#include "neopixel.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>


#define NEOPIXEL_PORT &PORTD
#define NEOPIXEL_PIN_MASK (1 << 5)
#define NEOPIXEL_NUM_LEDS 12
#define NEOPIXEL_COLORS_PER_LED 3
#define NEOPIXEL_BYTES_PER_COLOR 2
#define NEOPIXEL_BUFFER_SIZE (NEOPIXEL_NUM_LEDS * NEOPIXEL_COLORS_PER_LED * NEOPIXEL_BYTES_PER_COLOR)

void NeoPixelInit(void);
void NeoPixelSetBrightness(uint8_t b);
void NeoPixelSetPixelColor(uint8_t n, uint8_t r, uint8_t g, uint8_t b);
void NeoPixelUpdate(void);

#endif /* NEOPIXEL_H_ */