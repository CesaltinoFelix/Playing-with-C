#include <stdio.h>

int main()
{
   unsigned int firtsTwo, lastTwo, sum ,result;

    for (size_t num = 1000; num < 9999; num++)
    {
        firtsTwo = num / 100;
        lastTwo = num % 100;

        sum = firtsTwo + lastTwo;
        result = sum * sum;

        if (result == num)
        {
            printf("%d + %d = %d equivale a %d\n", firtsTwo, lastTwo, sum, result);
        }
        
        

    }
}