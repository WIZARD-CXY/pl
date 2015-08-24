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

struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        // from tail to head find the first decresing element
        int i;
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        
        if(i<0){
            //already the last permutation
            reverse(nums.begin(),nums.end());
        }
        //find the first element larger than nums[i]
        int k=n-1;
        
        while(k>i){
            if(nums[k]>nums[i]){
                break;
            }
            k--;
        }
        
        swap(nums[k],nums[i]);
        reverse(nums.begin()+i+1,nums.end());
    }
};

void print(vector<int> &v){
    for(auto a :v){
        cout<<a<<" ";
    }
}

int main(){
    Solution sln;
    vector<int> vec={1,2};

    
    sln.nextPermutation(vec);
    print(vec);

}

