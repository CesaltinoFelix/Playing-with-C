#include <unistd.h>
void putch(char showNumber)
{
    write(1, &showNumber, 1);
}
void putnbr(int number)
{
    short i = 0;
    char v[10];
    long long n = number; // permite receber um valor com numeros de bits mmaiores do que um int.

    if (n < 0)
    {
        n *= -1;
        putch('-');
    }

    while (n % 10)
    {
        v[i++] = (n % 10) + 48;
        n = n / 10;
    }

    while (i >= 0)
    {
        write(1, &v[i--], 1);
        
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
