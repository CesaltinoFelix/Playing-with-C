#include <unistd.h>
void print_n_comb(int n);
int main(){
    print_n_comb(4);
}
void print_n_comb(int n){
    char v[10];
    char max_v[10];
    int cont = n - 1;
    int i = 0;
    while (i < n)
    {   
        v[i] = i + 48;

        max_v[i] = (10 - n) + i + 48;
        i++;
    }

    
 while (v[0] != max_v[0])
 {

       while (v[cont] != max_v[cont])
    {   
      write(1, v, n);
      write(1, " ", 1);
       v[cont]++;
    }

    cont--;
 }
 

    

    
}
