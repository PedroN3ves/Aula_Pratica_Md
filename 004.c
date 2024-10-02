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
                n /= div;
            }
        }
        div += 1;
    }
}

int mdc(int fatores1[], int tamanho1, int fatores2[], int tamanho2)
{
    int i = 0, j = 0, resultado_mdc = 1;

    while (i < tamanho1 && j < tamanho2)
    {
        if (fatores1[i] == fatores2[j])
        {
            resultado_mdc *= fatores1[i];
            i++;
            j++;
        }
        else if (fatores1[i] < fatores2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return resultado_mdc;
}

int mmc(int fatores1[], int tamanho1, int fatores2[], int tamanho2)
{
    int i = 0, j = 0, resultado_mmc = 1;

    while (i < tamanho1 && j < tamanho2)
    {
        if (fatores1[i] == fatores2[j])
        {
            resultado_mmc *= fatores1[i];
            i++;
            j++;
        }
        else if (fatores1[i] < fatores2[j])
        {
            resultado_mmc *= fatores1[i];
            i++;
        }
        else
        {
            resultado_mmc *= fatores2[j];
            j++;
        }
    }

    while (i < tamanho1)
    {
        resultado_mmc *= fatores1[i];
        i++;
    }
    while (j < tamanho2)
    {
        resultado_mmc *= fatores2[j];
        j++;
    }

    return resultado_mmc;
}

int main()
{
    int n1, fatores_n1[100], tamanho_n1;
    int n2, fatores_n2[100], tamanho_n2;

    scanf("%d%d", &n1, &n2);

    int *ptr_tamanho_n1 = &tamanho_n1;
    int *ptr_tamanho_n2 = &tamanho_n2;

    decompor_primos(n1, fatores_n1, ptr_tamanho_n1);
    decompor_primos(n2, fatores_n2, ptr_tamanho_n2);

    int resultado_mdc = mdc(fatores_n1, tamanho_n1, fatores_n2, tamanho_n2);
    int resultado_mmc = mmc(fatores_n1, tamanho_n1, fatores_n2, tamanho_n2);

    printf("MDC: %d\n", resultado_mdc);
    printf("MMC: %d\n", resultado_mmc);

    return 0;
}
