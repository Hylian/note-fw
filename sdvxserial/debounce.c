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
  uint32_t time;
  bool level;
} sPinDebounce;

sPinDebounce pins[NUM_PINS] = {0};

void DebounceInit(void)
{
  /* Setup Debounce Timer */
/*
  TCCR1B |= (1 << CS10);
  TCNT1 = 0;
*/
}

void DebounceUpdate(void)
{
  
}