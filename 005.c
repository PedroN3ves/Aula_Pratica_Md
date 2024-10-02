#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int euclides(int a, int d)
{
    int q, r, res;
    q = a / d;
    r = a % d;

    if (r == 0)
    {
        res = d;
    }
    else
    {
        a = d;
        d = r;
        res = euclides(a, d);
    }

    return res;
}

int main()
{
    int n1, n2, mdc;
    scanf("%d%d", &n1, &n2);

    mdc = euclides(n1, n2);
    printf("MDC = %d", mdc);

    return 0;
}