#include <stdio.h>
#include <string.h>

int main ()
{
  char fresa[]   = "apple";
  char mirrey[]  = "apple";
  char chairo[]  = "android";

  if( strcmp(fresa, mirrey) == 0)
  {
      printf("fresa y mirrey son iguales\r\n");
  }
  if(strcmp(fresa, chairo) != 0)
  {
      printf("mirrey y chairo no son iguales\r\n");
  }

  return 0;
}