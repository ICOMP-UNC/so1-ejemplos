#include <stdio.h>

/*

Example: Find frequency of character in a string
++++++++++++++++++++++++++++++++++++++++++++++++


*/

int main()
{
  char str[1000], ch;
  int i, frequency = 0;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin); // read string from user
  // gets(str); // deprecated

  printf("Enter a character to find the frequency: ");
  scanf("%c",&ch);

  for (i = 0; str[i] != '\0'; ++i) {
     if (ch == str[i]) ++frequency;
  }

  printf("Frequency of %c = %d", ch, frequency);

  return 0;
}
