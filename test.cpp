#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int> > res;
        int n=nums.size();
        vector<int> temp;
        
        for(int i=0;i<(1<<n); i++){
            
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
                
            res.push_back(temp);
            temp.clear();
            
        }
        return res;
    }
int main(){
   vector<int> a;
   a.push_back(0);

   subsets(a);
}