#include <unistd.h>

void ft_putchar(char num){
    write(1, &num,1);
}

void ft_putnbr(int n){
    long long num = n;
    char v[10];
    int i = 0;

    if (num < 0)
    {
        num *= -1;
        write(1, "-", 1);
    }

    while (num != 0)
    {
        v[i] = (num % 10) + '0';
        num /= 10;
        i++;
    }

    while (i >= 0)
    {
         write(1, &v[--i],1);
        
    }
    
}
int main(){

     ft_putnbr(-2147483648);
     write(1, "\n", 1);
     ft_putnbr(2147483647);
}