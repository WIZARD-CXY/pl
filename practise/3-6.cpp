#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

// compare two circular string
int Isless(string &s, int p, int q)
{
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[(p + i) % len] != s[(q + i) % len])
        {
            return s[(p + i) % len] < s[(q + i) % len];
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for (int p = 1; p < len; p++)
    {
        if (Isless(s, p, ans))
        {
            ans = p;
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%c", s[(i + ans) % len]);
    }
    printf("\n");
}