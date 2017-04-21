#ifndef ENCODER_H_
#define ENCODER_H_

#include "encoder.h"
#include <avr/io.h>
#include <stdbool.h>

void EncoderInit(void);
void EncoderUpdate(void);
int EncoderGetLeftDelta(void);
int EncoderGetRightDelta(void);

#endif /* ENCODER_H_ */