class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int start=0;
        int end=0;
        int minlen=INT_MAX;
        int sum=0;
        
        while(end<nums.size()){
            sum+=nums[end];
            
            if(sum>=s){
                // try to move start forward
                while(start<nums.size() && sum>=s){
                    sum-=nums[start];
                    start++;
                }
                //start-1 to end is just fit 
                int len=end-(start-1)+1;
                
                if(minlen>len){
                    minlen=len;
                }
            }
            end++;
        }
        if(minlen==INT_MAX){
            return -1;
        }
        
        return minlen;
    }
};
