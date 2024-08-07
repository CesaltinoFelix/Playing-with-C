#include <unistd.h>
void print_number(int n)
{
    if (n < 10)
    {
        char temp = n + '0';
        write(1, "0", 1);
        write(1, &temp, 1);
    }
    else
    {
        char temp = n / 10 + '0';
        write(1, &temp, 1);
        temp = n % 10 + '0';
        write(1, &temp, 1);
    }
}
void ft_print_comb2(void)
{
    char v[2];
    v[0] = 0;

    while (v[0] <= 98)
    {
        v[1] = v[0] + 1;
        while (v[1] <= 99)
        {
            print_number(v[0]);
            write(1, " ", 1);
            print_number(v[1]);
            if (v[0] == 98 && v[1] == 99)
                write(1, ".", 1);
            else
                write(1, ",", 1);

            v[1]++;
        }
        v[0]++;
    }
}

int main()
{
    ft_print_comb2();
}