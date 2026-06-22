#include <stdio.h>

int main() {
    int i;
    float f;
    char c;

    printf("Enter an integer, a float, and a character: ");
    scanf("%d %f %c", &i, &f, &c);

    printf("You entered:\nInteger: %d\nFloat: %.2f\nCharacter: %c\n", i, f, c);
    return 0;
}
