#include <stdio.h>
int main() {
    int n, original, remainder, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;
  while (n > 0) {
        remainder = n % 10;
        int fact = 1;
        for (int i = 1; i <= remainder; i++) {
            fact *= i;
        }
        sum += fact;
        n /= 10;
    }
  if (sum == original) printf("%d is a Strong number.\n", original);
  else printf("%d is not a Strong number.\n", original);
    return 0;
}
