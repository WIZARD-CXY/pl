class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        int n=nums.size();
        
        if(n<k){
            return res;
        }
        
        // prepare a deque to maintain index of window
        // qq.front() is the window current max element index
        deque<int> qq;
        
        for(int i=0; i<nums.size(); i++){
            // moving window forward, need to delete pre window max
            // which is qq.front
            if(!qq.empty() && qq.front()==i-k){
                qq.pop_front();
            }
            while(!qq.empty() && nums[qq.back()] < nums[i]){
                //remove all the smaller element
                qq.pop_back();
            }
            qq.push_back(i);
            
            if(i>=k-1){
                res.push_back(nums[qq.front()]);
            }
        }
        return res;
    }
};

