#if 0
rm -f a.out
clang main.c
./a.out
exit
#endif

#include <stdio.h>

static inline void char11FromFloat(float v, char * outChar11) {
  unsigned b = ((unsigned *)(void *)&v)[0];
  sprintf(outChar11, "0x%X", b);
}

static inline float char11ToFloat(char * char11) {
  float v;
  sscanf(char11, "%X", (unsigned *)(void *)&v);
  return v;
}

int main() {
  float pi = 3.14159265f;

  char char11[11];
  char11FromFloat(pi, char11);

  float number = char11ToFloat(char11);

  printf("pi:     %f\n", pi);
  printf("char11: %s\n", char11);
  printf("number: %f\n", number);
  fflush(stdout);
}
