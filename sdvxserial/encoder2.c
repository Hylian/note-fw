#include "encoder2.h"

#define AL_MASK (1<<5)
#define BL_MASK (1<<6)
#define AR_MASK (1<<7)
#define BR_MASK (1<<0)

void EncoderInit(void)
{
  DDRB = 0x0;
}

static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
int8_t delta = 0;
  
void EncoderUpdate(void)
{
  static uint8_t old_AB = 0;
  bool new_A = (bool) (PINB & AR_MASK);
  bool new_B = (bool) (PINB & BR_MASK);
  old_AB <<= 2;
  old_AB |= (uint8_t) ( (new_A << 1) & new_B );
  delta = enc_states[( old_AB & 0x0f )];
}

int8_t EncoderGetDelta(void)
{
  int8_t ret = delta;
  delta = 0;
  return ret;
}
