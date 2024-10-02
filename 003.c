#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primo(int n, int div)
{
    if (n <= 2)
    {
        return (n == 2) ? 1 : 0;
    }
    if (n % div == 0)
    {
        return 0;
    }
    if (div * div > n)
    {
        return 1;
    }
    return primo(n, div + 1);
}

void decompor_primos(int n, int fatores[], int *tamanho)
{
    int div = 2;
    *tamanho = 0;

    while (n > 1)
    {
        if (primo(div, 2))
        {
            while (n % div == 0)
            {
                fatores[*tamanho] = div;
                (*tamanho) += 1;
                printf("%d\n", div);
                n /= div;
            }
        }
        div += 1;
    }
    printf("\n");
}

int main()
{
    int n, fatores[100], tamanho;
    scanf("%d", &n);

    int *ptr_tamanho = &tamanho;

    decompor_primos(n, fatores, ptr_tamanho);

    return 0;
}
