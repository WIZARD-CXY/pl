class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        
        if(n<k){
            return res;
        }
        
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front()==i-k){
                //pop the previous max idx since it is out of the window
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                //remove redundant element
                dq.pop_back();
            }
            //push the idx into the dq
            dq.push_back(i);
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};