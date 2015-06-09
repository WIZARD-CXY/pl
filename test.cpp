#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> mset;
        
        for(int i=0;i<nums.size();++i)
        {
            mset.insert(nums[i]);
            if(mset.size()==k+1)
            {
                auto it=mset.find(nums[i-k-1]);
                mset.erase(it);
            }
            int tmp=nums[i];
            auto it=mset.lower_bound(tmp-t);
            if(it!=mset.end())
            {
                int diff=abs(*it-tmp);
                if(diff<=t)
                    return true;
            }
           
        }
        return false;
    }


int main(){
   TreeNode *root= new TreeNode(1);
   TreeNode *left= new TreeNode(2);
   TreeNode *right= new TreeNode(3);
   root->left=left;
   root->right=right;

   zigzagLevelOrder(root);
}