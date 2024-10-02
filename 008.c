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

int inversoModular(int numero, int modulo)
{
    int s, t;
    int mdc = euclides(numero, modulo, &s, &t);

    if (mdc != 1)
    {
        printf("O inverso modular não existe, pois MDC(%d, %d) é diferente de 1\n", numero, modulo);
        return -1;
    }
    else
    {
        int inverso = (s % modulo + modulo) % modulo;
        return inverso;
    }
}

void resolverEquacao(int a, int b, int m)
{
    int inverso = inversoModular(a, m);

    if (inverso == -1)
    {
        printf("Nenhuma solucao para %dx congruente a %d (mod %d)\n", a, b, m);
        return;
    }

    int x = (inverso * b) % m;

    printf("Uma solucao para %dx congruente a %d (mod %d) eh: x = %d\n", a, b, m, x);
}

int main()
{
    int a, b, m;

    printf("Digite os valores de a, b e m, respectivamente, para a equacao ax congruente a b (mod m): ");
    scanf("%d %d %d", &a, &b, &m);

    resolverEquacao(a, b, m);

    return 0;
}
