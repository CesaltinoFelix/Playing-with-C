#include<stdio.h>

int main()
{
  int a = 1;

  int *b;
  b = &a;

  printf("Valor de a = %d\n", a);
  printf("Endereco de a = %p\n", &a);
  printf("Valor de b = %d\n", *b);
  printf("Endereco de b = %p\n", &b);
  printf("Ponteiro de b = %p\n", b);

  *b = 2;

  // printf("a = %d\n", a);
  // printf("b = %d\n", *b);

  return 0;   
}
