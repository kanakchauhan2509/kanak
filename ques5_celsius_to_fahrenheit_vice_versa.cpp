#include <stdio.h>
int main(){
  float celsius, fahrenheit;
int choice;
printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nEnter choice (1 or 2):");
scanf("%d",&choice);
if(choice == 1){
printf("Enter temperature in celsius:");
scanf("%f",&celsius);
fahrenheit = (celsius * 9 / 5) + 32;
printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
} else if ( choice == 2) {
printf("Enter temperature in Fahrenheit:");
scanf("%f", &fahrenheit);
celsius = (fahrenheit - 32) * 5 / 9;
printf("Temperature in Celsius: %.2f\n", celsius);
} else {
printf("Invalid choice!\n");
}
return 0;
}
