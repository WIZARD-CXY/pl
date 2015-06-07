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

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> mset;
        
        for(int i=0; i<nums.size(); i++)
        {
            mset.insert(nums[i]);
            if(mset.size()==k+2)
            {
                auto it=mset.find(nums[i-k]);
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
   vector<int> v;
   v.push_back(-1);
   v.push_back(-1);

   cout<<containsNearbyAlmostDuplicate(v,1,-1)<<endl;
}