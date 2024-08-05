#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int i = 0;
        int times;

        while(argv[1][i])
        {
            times = 1;
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                times = argv[1][i] - 'a' + 1;
            if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                times = argv[1][i] - 'A' + 1;

            while(times > 0)
            {
                write(1, &argv[1][i], 1);
                times--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}

