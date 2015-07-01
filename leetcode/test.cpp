#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long  res=0;
        
        while(x){
            res=res*10+x%10;
            if(res>INT_MAX){
                return 0;
            }else if(res<INT_MIN){
                return 0;
            }
            x/=10;
        }
        
        return res;
        
    }
};

int main(){
    Solution sln;
    cout<<sln.reverse(-1234);
}