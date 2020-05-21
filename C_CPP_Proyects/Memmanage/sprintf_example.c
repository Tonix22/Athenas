/* sprintf example */
#include <stdio.h>

int main ()
{
  char buffer [50];
  int hour    = 3;
  int minute  = 30;
  int second  = 5;
  sprintf(buffer,"Time is %02d : %02d : %02d\n", hour, minute, second);
  printf("%s",buffer);
  return 0;
}
