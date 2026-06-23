#include <stdio.h> 
int main() {
  int n, isPrime;
printf("Enter the value of N:);
  scanf("%d", &n);
printf("Prime number between 1 and %d are:", n);
for (int i = 2; i <= n; i++) {
isPrime = 1;
for(int j = 2; j * j <= i; j++0) {
if (i % j == 0) {
isPrime = 0;
break;
}
}
if (isPrime) {
printf("%d", i);
]
]
printf("\n");
return 0;
}
