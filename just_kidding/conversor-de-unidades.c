#include <stdio.h>

int main(){

    int n = 42;
    int base = 2;

    while (n)
    {
        printf("n = %d , base = %d -----> %d\n", n, base, n % base);
        n /= base;
    }
    
}