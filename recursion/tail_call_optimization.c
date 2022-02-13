#include <stdio.h>

int factorial(int n, int count) {
  if (n == 0) return count;

  return factorial(n - 1, n * count);
}

int main(void) {
  int num;

  printf("enter a number: ");
  scanf("%d", &num);

  printf("%d! = %d\n", num, factorial(num, 1));

  return 0;
}
