#include <unistd.h>

void show_number(int n){

    
    if (n < 10)
    {
        n = n + '0';
        write(1, "0", 1);
        write(1, &n , 1);
    }else{
        int one = (n/10) + '0';
        int two = (n%10) + '0';
        write(1, &one , 1);
        write(1, &two , 1);
    }
    
}
void ft_print_comb2(void)
{
    int v[2];
    v[0] = 0;

    while (v[0] < 99)
    {
        v[1] = v[0] + 1;

        while (v[1] < 100)
        {
            show_number(v[0]);
            write(1, " ", 1);
            show_number(v[1]);
            if(v[0] == 98 && v[1] == 99)     write(1, ".", 1);
            else write(1, ",", 1);
            
            v[1]++;
        }
        v[1] = 0;
        v[0]++;
    }


}

int main()
{
    ft_print_comb2();
}