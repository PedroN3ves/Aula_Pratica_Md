#include <stdio.h>

int mod_1, mod_2, mod_3;
int cong_1, cong_2, cong_3;
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

int resolver_cong(int cong_1, int cong_2, int cong_3, int mod_1, int mod_2, int mod_3)
{
    int x = 0;
    int N = mod_1 * mod_2 * mod_3;

    for (x = cong_1; x < N; x += mod_1)
    {
        if ((x % mod_2 == cong_2) && (x % mod_3 == cong_3))
        {
            return x;
        }
    }
    return -1;
}

int main()
{

    printf("Digite o valor do primeiro mod (%%): ");
    scanf("%d", &mod_1);

    printf("Digite o valor do segundo mod (%%): ");
    scanf("%d", &mod_2);

    printf("Digite o valor do terceiro mod (%%): ");
    scanf("%d", &mod_3);

    if (mdc(mod_1, mod_2) != 1 || mdc(mod_1, mod_3) != 1 || mdc(mod_2, mod_3) != 1)
    {
        printf("Os modulos nao sao coprimos, logo, impossivel encontrar um valor que venha satisfazer todas as congruencias.\n");
        return 0;
    }

    printf("Digite o valor da primeira congruencia: ");
    scanf("%d", &cong_1);

    printf("Digite o valor da segunda congruencia: ");
    scanf("%d", &cong_2);

    printf("Digite o valor da terceira congruencia: ");
    scanf("%d", &cong_3);

    int resultado = resolver_cong(cong_1, cong_2, cong_3, mod_1, mod_2, mod_3);
    int prod_mod = mod_1 * mod_2 * mod_3;

    if (resultado != -1)
    {
        printf("O valor de x que satisfaz as congruencias eh: %d (mod %d)\n", resultado, prod_mod);
    }
    else
    {
        printf("Nao foi possivel encontrar um valor que venha satisfazer todas as congruencias.\n");
    }

    return 0;
}