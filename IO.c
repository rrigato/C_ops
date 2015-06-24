#include "stdio.h"
int main ()
{
    char prompt []  = "Enter a number, a character, and a string of characters: ";
    char letter;
    char  *char_string  [25];
    int value;
  	printf("Hello World!\n");
  	scanf("%d %c %s", &value, &letter, &char_string);
  	int i =0;
  	while (char_string[i] != "/0")
  	{
  	    printf("%s", char_string[i]);
  	    i++;
  	}
  return 0;
}
