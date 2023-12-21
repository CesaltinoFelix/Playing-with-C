#include <unistd.h>
#include <stdio.h>
void putch(char showNumber)
{
    write(1, &showNumber, 1);
}
void putnbr(int number)
{
    
    long  n = (long)number; //permite receber um valor com numeros de bits mmaiores do que um int.
    printf("\n%ld\n",n);

    if (n < 0)
    {
        n *= -1;
        putch('-');
    }
    if (n < 10)
    {
        putch(n + '0');
    }
    else
    {
        int casasDecimais = 1;
        long num = n;

        while (num >= 10)
        {
            num = num / 10;
            casasDecimais *= 10;
        }

        while (casasDecimais != 0)
        {
            putch((n / casasDecimais) + '0');
            n %= casasDecimais;
            casasDecimais /= 10;
        }
    }
}
int main()
{
    // putnbr(0);
    // write(1, "\n", 1);
    putnbr(-2147483648);
    // write(1, "\n", 1);
    // putnbr(2147483647);
    // write(1, "\n", 1);
    // putnbr(-9);
    // write(1, "\n", 1);
    // putnbr(42);
}
