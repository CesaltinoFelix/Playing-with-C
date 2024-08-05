#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

__pid_t id;
void my_handler_INT(int signal)
{
    printf("DELLING WITH THE SIGNAL %d\n", signal);
}

void my_handler_TERM(int signal)
{
    printf("TERM: DELLING WITH THE SIGNAL %d\n", signal);
    kill(id, SIGKILL);
}

int main(void)
{

    id = getpid();
    signal(SIGINT, my_handler_INT);
    signal(SIGTERM, my_handler_TERM);

    while(1)
    {
        printf("RUNNING FOREVER!!! => %d\n", id);
        sleep(1);
    }

    return (0);
}