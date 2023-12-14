#include <unistd.h>

int main(){

    char info[] = "Digite a letra: ";
    int numero;
    int i = 0;
    while (info[i] != '\0')
    {
        write(1, &info[i], 1);
        i++;
    }
    
    read(0, &numero, sizeof(numero));
    write(1, &numero, 4);
}