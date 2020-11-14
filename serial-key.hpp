#ifndef serial_key_h
#define serial_key_h

extern bool valKey[2];
extern bool valKey_old[2];
extern int pinKey[2];


void keyInit(void);

bool keyPressed(int nr);

void keyEdgeDetect (bool serialToOledOn);

#endif //serial_key_h
