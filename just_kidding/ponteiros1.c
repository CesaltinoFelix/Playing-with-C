#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 20;
    int *p1 = NULL;
    int *p2 = NULL;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n\n", &p2, p2);

    p1 = &a;
    p2 = p1;
    *p2 = 10;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n\n", &p2, p2);

    int **p3 = NULL;
    printf("&p3 = %p, p3 = %p\n\n", &p3, p3);

    p3 = &p2;

    printf("&p3 = %p, p3 = %p, *p3 = %d\n\n", &p3, p3, *(*p3));
    return 0;
}
