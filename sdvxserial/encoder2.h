/*
 * encoder2.h
 *
 * Created: 4/23/2017 5:55:43 PM
 *  Author: Edward
 */ 


#ifndef ENCODER2_H_
#define ENCODER2_H_

#include "encoder2.h"
#include <avr/io.h>
#include <stddef.h>
#include <stdbool.h>

void EncoderInit(void);
void EncoderUpdate(void);
int8_t EncoderGetDelta(void);

#endif /* ENCODER2_H_ */