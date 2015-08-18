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
    vector<int> singleNumber(vector<int>& nums) {
        int tmp=0;
        
        for(auto num : nums){
            tmp^=num;
        }
        cout<<tmp<<endl;
        
        int diffpos=0;
        for(int i=0; i<32; i++){
            if((tmp&(1<<i))){
                diffpos=i;
                break;
            }
        }
        
        vector<int> groupa;
        vector<int> groupb;
        cout<<diffpos<<endl;                    

        
        for(auto num :nums){
            if(num&(1<<diffpos)){
                groupa.push_back(num);
            }else{
                groupb.push_back(num);
            }
        }
        print(groupa);
        print(groupb);
        
        int a=0;
        
        for(auto num: groupa){
            a^=num;
        }
        
        int b=0;
        
        for(auto num: groupb){
            b^=num;
        }
        
        return {a,b};
    }
};

void print(vector<int> &a){
    for(auto num : a){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution sln;
    vector<int> s={1,2,1,3,5,2};
    
    sln.singleNumber(s);

}

