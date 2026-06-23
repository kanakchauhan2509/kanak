#include <stdio.h>
int main() {
  char c;
int isLowercaseVowel, isUppercaseVowel;
printf("Enter an alphabet character");
scanf("%c", &c);
isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
if(isLowercaseVowel || isUppercaseVowel)
  printf("%c is a vowel\n", c);
else
  printf("%c is a consonent\n", c);
} else {
printf("%c is not a valid alphabet character\n", c);
}
return 0;
}
