#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int maxIdx=0;
        
        for(int i=0; i<A.size();i++){
            maxIdx=(i+A[i],maxIdx);
            if(maxIdx>=A.size()-1){
                return true;
            }
            if(A[i]==0 && maxIdx==i){
                return false;
            }
        }
        
        return true;
    }
};



int main(){
    Solution sln;
    vector<int> a{2,1,0,2,3,2,8,5,7,10,9,9,6,6,3,4,2,9,9,0};
    cout<<sln.canJump(a);
}

