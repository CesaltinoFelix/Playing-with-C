#include <unistd.h>

int main() {
    char letra_maiuscula = 'A';
    char letra_minuscula = 'a';

    while (letra_maiuscula <= 'Z' && letra_minuscula <= 'z') {
        write(1, &letra_maiuscula, 1);
        write(1, &letra_minuscula, 1);

        letra_maiuscula += 2;  // Incrementa para a pr�xima letra mai�scula
        letra_minuscula += 2;  // Incrementa para a pr�xima letra min�scula
    }

    write(1, "\n", 1);

    return 0;
}
