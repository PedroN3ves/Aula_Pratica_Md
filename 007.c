#include <stdio.h>

int euclides(int a, int b, int *s, int *t)
{

    if (b == 0)
    {
        *s = 1;
        *t = 0;
        return a;
    }

    int sTemp, tTemp;

    int mdc = euclides(b, a % b, &sTemp, &tTemp);

    *s = tTemp;
    *t = sTemp - (a / b) * tTemp;

    return mdc;
}

int encontrarInversoModular(int numero, int modulo)
{
    int s, t;
    int mdc = euclides(numero, modulo, &s, &t);

    if (mdc != 1)
    {
        printf("O inverso do mod nao existe, pois o MDC(%d, %d) eh diferente de 1\n", numero, modulo);
        return -1;
    }
    else
    {
        int inverso = (s % modulo + modulo) % modulo;
        return inverso;
    }
}

int main()
{
    int valorA, valorB;

    printf("Digite os valores de a e b: ");
    scanf("%d %d", &valorA, &valorB);

    int inversoModular = encontrarInversoModular(valorA, valorB);

    if (inversoModular != -1)
    {
        printf("Inverso de %d mod %d eh: %d\n", valorA, valorB, inversoModular);
    }

    return 0;
}