#include <unistd.h>

void ft_putchar_reverse(void){

    char letter = 'z';

    while (letter >= 'a')
    {
        write(1, &letter, 1);
        write(1, "\n", 1);
        letter--;
    }
    
}
int main(){
    ft_putchar_reverse();
}