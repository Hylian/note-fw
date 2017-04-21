#include "encoder.h"

static bool al_prev, bl_prev, ar_prev, br_prev;
static int l_delta, r_delta;

#define AL_MASK (1<<5)
#define BL_MASK (1<<6)
#define AR_MASK (1<<7)
#define BR_MASK (1<<0)

void EncoderInit(void)
{
  DDRB = 0x0;
  al_prev = (bool) (PINB & AL_MASK);
  bl_prev = (bool) (PINB & BL_MASK);
  ar_prev = (bool) (PINB & AR_MASK);
  br_prev = (bool) (PINB & BR_MASK);
}

void EncoderUpdate(void)
{
  bool update = false;
  bool al, bl, ar, br;
  bool al_changed, bl_changed, ar_changed, br_changed;
  bool l_cw = 0, l_ccw = 0, r_cw = 0, r_ccw = 0;
  
  al = (bool) (PINB & AL_MASK);
  bl = (bool) (PINB & BL_MASK);
  ar = (bool) (PINB & AR_MASK);
  br = (bool) (PINB & BR_MASK);
  
  al_changed = al ^ al_prev;
  bl_changed = bl ^ bl_prev;
  ar_changed = ar ^ ar_prev;
  br_changed = br ^ br_prev;

  if (!(al_changed && bl_changed)) {
    l_cw = (al_changed & ((al & !bl) || (!al & bl))) ||
           (bl_changed & ((bl & al) || (!bl & !al)));
    l_ccw = (al_changed || bl_changed) && !l_cw;
  }

  if (!(ar_changed && br_changed)) {
    r_cw = (ar_changed & ((ar & !br) || (!ar & br))) ||
           (br_changed & ((br & ar) || (!br & !ar)));
    r_ccw = (ar_changed || br_changed) && !r_cw;
  }

  l_delta = l_delta + l_cw - l_ccw;
  r_delta = r_delta + r_cw - r_ccw;

  al_prev = al;
  bl_prev = bl;
  ar_prev = ar;
  br_prev = br;
}

int EncoderGetLeftDelta(void)
{
  int ret = l_delta;
  l_delta = 0;
  return ret;
}

int EncoderGetRightDelta(void)
{
  int ret = r_delta;
  r_delta = 0;
  return ret;
}