#include <stdio.h>

int factorial(int n) {
  if (n == 0) return 1;

  return n * factorial(n - 1);
}

int main(void) {
  int num;

  printf("enter a number: ");
  scanf("%d", &num);

  printf("%d! = %d\n", num, factorial(num));

  return 0;
}
