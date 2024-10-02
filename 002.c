#include <stdio.h>
#include <math.h>
#include <time.h>
//Escrever um programa para listar números primos sequencialmente. 
//Você deve otimizar o programa para que ele liste o maior número possível de primos em 60 segundos

int numeroprimo(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    time_t quandocomeca = time(NULL);
    time_t tempoatual;
    int num = 2;  
    int contadordeprimo = 0;

    while ((tempoatual = time(NULL)) - quandocomeca < 60) {
        if (numeroprimo(num)) {
            printf("%d\n", num);
            contadordeprimo++;
        }
        num++;
    }

    printf("Total de primos encontrados em 60 segundos: %d\n", contadordeprimo);
    return 0;
}