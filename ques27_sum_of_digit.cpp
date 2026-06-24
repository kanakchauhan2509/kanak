#include <stdio.h>

int main() {
    int num, sum = 0, remainder;
  printf("Enter a number: ");
  scanf("%d", &num);
  if (num < 0) {
        num = -num;
    }
  while (num > 0) {
        remainder = num % 10; // Extract the last digit
        sum += remainder;     // Add it to the sum
        num /= 10;            // Drop the last digit
    }
  printf("Sum of digits: %d\n", sum);
    return 0;
}
