#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

vector<vector<int> > res;
void solve(int n, vector<int> &temp, vector<int> nums,vector<bool> used){
    if(temp.size()==n){
        
        res.push_back(temp);
        
    }else{
        for(int i=0; i<nums.size(); i++){
            if(used[i] || (i!=0 && nums[i-1]==nums[i] && used[i-1]) ){
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=1;
            solve(n,temp,nums,used);
            used[i]=0;
            temp.pop_back();
        }
    }
}
vector<vector<int> > permuteUnique(vector<int>& nums) {
    
    sort(nums.begin(),nums.end());
    vector<bool> used(nums.size(),0);
    vector<int> temp;
    
    solve(nums.size(),temp,nums,used);
    
    return res; 
    
}




int main(){
    vector<int> test;
    test.push_back(1);test.push_back(1);test.push_back(3);test.push_back(4);

    vector<vector<int> > res=permuteUnique(test);
    
}