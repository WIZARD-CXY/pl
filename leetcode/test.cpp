#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<2){
            return 0;
        }
        
        int pre[n]={0};//record from 0 to i day's max profit
        int post[n]={0};//record from i to n-1 day's max profit
        
        int minV=prices[0];
        
        for(int i=1; i<n; i++){
            minV=min(minV,prices[i]);
            pre[i]=max(pre[i-1],prices[i]-minV);
        }
        
        int maxV=prices[n-1];
        
        for(int i=n-2; i>=0; i--){
            maxV=max(maxV,prices[i]);
            post[i]=max(post[i+1],maxV-prices[i]);
        }
        
        int res=0;
        
        for(int i=0; i<n; i++){
            res=max(res,pre[i]+post[i]);
        }

        for(int i=0; i<n; i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++){
            cout<<post[i]<<" ";
        }
        cout<<endl;
        return res;
    }
};

int main(){
    Solution sln;

    vector<int> words;
    words.push_back(2);
    words.push_back(1);
    sln.maxProfit(words);
}