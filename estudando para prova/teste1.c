#include <unistd.h>

void ft_putnbr(int num)
{

    if(num >= 10 )
        ft_putnbr(num / 10);
    char res = num % 10 + '0';
    write(1, &res, 1);
}
// 1 0
int main(void)
{
    int i = 1;
    while(i <= 100)
    {
        if(i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if(i % 3 == 0)
            write(1, "fizz", 4);
        else if(i % 5 == 0)
            write(1, "buzz", 4);
        else ft_putnbr(i);
            write(1, "\n", 1);
        i++;
    }
}