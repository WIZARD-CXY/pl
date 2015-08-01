class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        deque<int> q;
        
        for(int i=0; i<nums.size(); i++){
            if(!q.empty() && q.front()==i-k){
                // window move right, delete the leftmost one
                q.pop_front();
            }
            
            while(!q.empty() && nums[q.back()]<nums[i]){
                //remove all the smaller element than nums[i] element
                q.pop_back();
            }
            q.push_back(i);
            //start to record
            if(i>=k-1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};