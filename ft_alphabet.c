#include <unistd.h>

void ft_putchar(void){

    char letter = 'a';

    while (letter <= 'z')
    {
        write(1, &letter, 1);
        write(1, " ", 1);
        letter++;
    }
    
}

int main(){
    ft_putchar();
}