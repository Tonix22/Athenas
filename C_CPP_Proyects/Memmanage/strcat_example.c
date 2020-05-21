/* strcat example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[80];
  strcpy (str,"Athenas ");
  strcat (str,"is ");
  strcat (str,"super ");
  strcat (str,"cool");
  printf("%s",str);
  return 0;
}