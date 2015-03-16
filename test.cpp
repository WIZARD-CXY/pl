#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor ==-1) return INT_MAX;
    long long a = labs(dividend);
    long long b = labs(divisor);
    long long res = 0;
    while(a >= b)
    {
        long long c = b;
        for(int i = 0; a >= c; i++, c <<=1)
        {
            a -= c;
            res += 1<<i;
        }
    }

    return ((dividend ^ divisor) >> 31) ? (-res) : (res);
}


int main(){
    cout<<labs(INT_MIN)<<endl;
    
    cout<<divide(INT_MIN,-1)<<endl;

}