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

int main()
{
    int a, b, s, t;

    scanf("%d %d", &a, &b);

    int mdc = euclides(a, b, &s, &t);

    printf("MDC: %d\nCombinacao linear: %d*%d + %d*%d\n", mdc, s, a, t, b);
    return 0;
}