#include "encoder.h"

#define AL_MASK (1<<5)
#define BL_MASK (1<<6)
#define AR_MASK (1<<7)
#define BR_MASK (1<<0)

static uint8_t old_AB_left = 0;
static uint8_t old_AB_right = 0;
static const int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
int8_t delta_left = 0;
int8_t delta_right = 0;

void EncoderInit(void)
{
  DDRB = 0x0;
}
  
void EncoderUpdate(void)
{
  uint8_t port = PINB;
  bool new_A_left = (bool) (port & AL_MASK);
  bool new_B_left = (bool) (port & BL_MASK);
  bool new_A_right = (bool) (port & AR_MASK);
  bool new_B_right = (bool) (port & BR_MASK);

  old_AB_left <<= 2;
  old_AB_left |= (uint8_t) ( (new_A_left << 1) | new_B_left );
  
  old_AB_right <<= 2;
  old_AB_right |= (uint8_t) ( (new_A_right << 1) | new_B_right );
  
  delta_left = enc_states[( old_AB_left & 0x0f )];
  delta_right = enc_states[( old_AB_right & 0x0f )];
}

int8_t EncoderGetLeftDelta(void)
{
  int8_t ret = delta_left;
  delta_left = 0;
  return ret;
}

int8_t EncoderGetRightDelta(void)
{
  int8_t ret = delta_right;
  delta_right = 0;
  return ret;
}