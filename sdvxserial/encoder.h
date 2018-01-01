#ifndef ENCODER_H_
#define ENCODER_H_

#include "encoder.h"
#include <stdint.h>

void EncoderInit(void);
void EncoderUpdate(void);
int8_t EncoderGetLeftDelta(void);
int8_t EncoderGetRightDelta(void);

#endif /* ENCODER_H_ */