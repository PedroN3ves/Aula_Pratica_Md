#include <stdio.h>

int temp;

int mdc(int a, int b)
{
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sao_coprimos(int mods[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mdc(mods[i], mods[j]) != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int resolver_cong(int congs[], int mods[], int n)
{
    int N = 1;
    for (int i = 0; i < n; i++)
    {
        N *= mods[i];
    }

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int Ni = N / mods[i];
        int Mi = 1;

        while ((Ni * Mi) % mods[i] != 1)
        {
            Mi++;
        }

        x += congs[i] * Ni * Mi;
    }

    return x % N;
}

int main()
{
    int n;

    printf("Digite o numero de congruencias (n): ");
    scanf("%d", &n);

    int congs[n], mods[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor da congruencia %d: ", i + 1);
        scanf("%d", &congs[i]);

        printf("Digite o valor do modulo %d (%%): ", i + 1);
        scanf("%d", &mods[i]);
    }

    if (!sao_coprimos(mods, n))
    {
        printf("Os modulos nao sao coprimos, logo, impossivel encontrar um valor que satisfaca todas as congruencias.\n");
        return 0;
    }

    int resultado = resolver_cong(congs, mods, n);
    int prod_mod = 1;
    for (int i = 0; i < n; i++)
    {
        prod_mod *= mods[i];
    }

    printf("O valor de x que satisfaz as congruencias eh: %d (mod %d)\n", resultado, prod_mod);

    return 0;
}