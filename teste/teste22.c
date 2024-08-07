#include <unistd.h>

int main()
{

    int v[3];

    v[0] = 0;

    while (v[0] < 8)
    {
        v[1] = v[0] + 1;

        while (v[1] < 9)
        {
            v[2] = v[1] + 1;
            while (v[2] < 10)
            {
                int n1 = v[0] + '0';
                int n2  = v[1] + '0';
                int n3 = v[2] + '0';
                write(1, &n1, 1);
                write(1, &n2, 1);
                write(1, &n3, 1);
                if (v[0] == 7 && v[1] == 8 && v[2] == 9)
                {
                    write(1, ".", 1);
                }
                else
                {
                    write(1, ",", 1);
                    write(1, " ", 1);
                }
                v[2]++;
            }

            v[2] = 0;
            v[1]++;
        }

        v[1] = 0;
        v[0]++;
    }
}