#include <stdio.h>

void strcpy_test(char *s, char *t)
{
  while(*s++ = *t++);
}

void strcat_test(char *s, char *t){
    while(*++s);
    while(*s++ = *t++);
}


int main(void)
{
  char testbuff[128];

  char *test[] =
  {
    "",
    "1",
    "12",
    "123",
    "1234"
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t thistest;
  size_t inner;

  printf("%d,%d,%d",sizeof test, sizeof test[0],numtests);
  for(thistest = 0; thistest < numtests; thistest++)
  {
    for(inner = 0; inner < numtests; inner++)
    {
      strcpy_test(testbuff, test[thistest]);
      strcat_test(testbuff, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
    }
  }

  return 0;
}


