#ifndef serial-keyhandling_h
#define serial-keyhandling_h

extern bool valKey[2];
extern bool valKey_old[2];
extern int pinKey[2];


void keyInit(void);

bool keyPressed(int nr);

void keyEdgeDetect (void);

#endif //serial-keyhandling_h
