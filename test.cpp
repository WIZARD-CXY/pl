#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
using namespace std;

int reverse(int x) {
        
        int sign=1;
        if(x<0){
            sign=-1;
            x=-x;
        }
        long long res=0;
        
        while(x){

            res=res*10+x%10;
            if(res*sign> INT_MAX || res*sign < INT_MIN){
                return 0;
            }
            
            x/=10;
            
        }
        
        
        return (int)res*sign;
        
    }


int main(){
    cout<<reverse(1534236469)<<endl;
    int a=2;
    int b=0;

    cout<<"haha"<<a*1.0/b<<endl;

}