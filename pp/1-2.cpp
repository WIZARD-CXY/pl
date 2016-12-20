#include <cstdio>

const int bitsperword = 32;
const int shift = 5;
const int mask = 0x1f;
const int n = 1e7;

int a[1 + n / bitsperword];

void set(int i)
{
    a[i >> shift] |= (1 << (i & mask));
}

void clr(int i)
{
    a[i >> shift] &= ~(1 << (i & mask));
}

int test(int i)
{
    return a[i >> shift] & (1 << (i & mask));
}

int main()
{
    int i;

    for (int i = 0; i < n; i++)
    {
        clr(i);
    }

    while (scanf("%d", &i) != EOF)
    {
        set(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (test(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}