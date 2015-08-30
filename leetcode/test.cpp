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
    int mySqrt(int x) {
        cout<<LONG_MAX<<" "<<LONG_MIN<<endl;
        int l=0;
        int r=x/2+2;
        
        while(l<r){
            int mid=l+((r-l)>>1);
            long long tmp=(long long)mid*mid;
            cout<<mid<<" "<<tmp<<endl;
            
            if(x==tmp){
                return mid;
            }else if (x<tmp){
               r=mid;
            }else{
               l=mid+1;
            }
        }
        
        return l-1;
    }
};

int main(){
    Solution sln;

    cout<<sln.mySqrt(2147395599);

    int a=INT_MIN;
    while(a){
        cout<<a<<endl;
        a/=2;
    }
    cout<<-INT_MIN-1<<" "<<INT_MIN<<endl;

}

