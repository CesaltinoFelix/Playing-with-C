#include <unistd.h>

void print_number(char v[]){
    if (v[0] == '7' && v[1] == '8' && v[2] == '9')
        write(1, v, 3);
    else write(1, v, 5);
}

void ft_print_comb(void){
    char v[5];
    v[0] = '0';
    v[3] = ',';
    v[4] = ' ';

    while (v[0] <= '7')
    {
        v[1] = v[0] + 1;
        while (v[1] <= '8')
        {
            v[2] = v[1] + 1;

            while (v[2] <= '9')
            {
                print_number(v);

                v[2]++;
            }
            v[1]++;
        }
        v[0]++;
    }
    
}


int main(){
    ft_print_comb();
}