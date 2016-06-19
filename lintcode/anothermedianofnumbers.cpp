class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> res;
        priority_queue<int> small,large;
        // small stores the smaller half of the elements and is a max-heap
        // large stores the larger half of the elements and is a min-heap
        // default priority queue is max-heap so use negative
        
        for(int i=0; i<nums.size(); i++){
            if(!large.empty() && -large.top()<nums[i]){
                // nums[i] belongs to the large
                large.push(-nums[i]);
            }else{
                small.push(nums[i]);
            }
            
            // balance the small and large
            // make small's size always equal or 1 element larger than large
            if(small.size()>large.size()+1){
                // move one element from small to large
                large.push(-small.top());
                small.pop();
            }else if(small.size()<large.size()){
                //move one element from large to small
                small.push(-large.top());
                large.pop();
            }
            
            res.push_back(small.top());
        }
                
        return res;
    }
};
