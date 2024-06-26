#include <unistd.h>

void printnumber(char hundreds, char tens, char ones)
{
    if (hundreds != tens && tens != ones)
    {
        if (hundreds < tens && tens < ones)
        {
            write(1, &hundreds, 1);
            write(1, &tens, 1);
            write(1, &ones, 1);
            if (hundreds != '7' || tens != '8' || ones != '9')
                write(1, ", ", 2);
        }
    }
}

void ft_print_comb(void)
{
    char hundreds;
    char tens;
    char ones;

    hundreds = '0';
    tens = '0';
    ones = '0';
    while (hundreds <= '9')
    {
        while (tens <= '9')
        {
            while (ones <= '9')
            {
                printnumber(hundreds, tens, ones);
                ones++;
            }
            ones = '0';
            tens++;
        }
        ones = '0';
        tens = '0';
        hundreds++;
    }
}

int main()
{
    ft_print_comb();
}