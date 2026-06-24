#include <stdio.h>
#include <math.h>
int main() {
    int n, original, remainder, result = 0, count = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
  original = n;
  while (original != 0) {
    original /= 10;
    count++;
    }
  original = n;
  while (original != 0) {
        remainder = original % 10;
        result += round(pow(remainder, count));
        original /= 10;
    }
  if (result == n) printf("%d is an Armstrong number.\n", n);
  else printf("%d is not an Armstrong number.\n", n);
    return 0;
}
