#include <stdio.h>
#include <stdbool.h>

bool primo(int n, int div)
{
    if (n <= 2)
    {
        if (n == 2)
        {
            return true;
        }
        return 0;
    }
    if (n % div == 0)
    {
        return false;
    }
    if (div * div > n)
    {
        return true;
    }
    return primo(n, div + 1);
}

int main()
{
    int n, res;
    scanf("%d", &n);

    res = primo(n, 2);
    printf("%d", res);

    return 0;
}