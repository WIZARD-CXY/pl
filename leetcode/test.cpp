#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
using namespace std;
void print(vector<int> &a); 

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            // in case n==INT_MIN promot to long long
            return 1.0/helper(x,-n);
        }
        return helper(x,n);
    }
    
    double helper(double x, int n){
        cout<<"helper "<<n<<endl;
        if(n==0){
            return 1.0;
        }
        
        if(n==1){
            return x;
        }
        
        double tmp=helper(x,n>>1);
        double res=tmp*tmp;
        
        if(n&1){
            res*=x;
        }
        
        return res;
    }
};

int main(){
    Solution sln;

    //cout<<sln.myPow(1.000000,INT_MIN);

    int a=INT_MIN;
    while(a){
        cout<<a<<endl;
        a/=2;
    }
    //cout<<-(INT_MIN+1)<<" "<<INT_MIN<<endl;

}

