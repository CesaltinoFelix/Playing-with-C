#include <stdio.h>
#include <unistd.h>

int main(void)
{
    
    while(1)
    {
        printf("\rCarregando   ");
        fflush(stdout);
        usleep(500000);

        printf("\rCarregando.");
        fflush(stdout);
        usleep(500000);

        
        printf("\rCarregando..");
        fflush(stdout);
        usleep(500000);

        
        printf("\rCarregando...");
        fflush(stdout);
        usleep(500000);
    }
    return (0);
}