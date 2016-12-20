#include <cstdio>
#include <algorithm>
using namespace std;

int compare(int &a, int &b)
{
    return a < b;
}

int a[100000];
int main()
{
    int i, n = 0;

    while (scanf("%d", &a[n]) != EOF)
    {
        n++;
    }

    sort(a, a + n, compare);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}