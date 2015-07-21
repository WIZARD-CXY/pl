class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        multiset<int> minheap,maxheap;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            if(!maxheap.empty() && nums[i]<=*maxheap.rbegin()){
                maxheap.insert(nums[i]);
            }else{
                minheap.insert(nums[i]);
            }
            
            // always keep maxheap.size() == minheap.size()
            // or just one element larger
            // then *maxheap.rbegin() is median
            if(maxheap.size() > minheap.size()+1){
                int num=*maxheap.rbegin();
                minheap.insert(num);
                maxheap.erase(maxheap.find(num));
                
            }else if(maxheap.size() < minheap.size()){
                int num=*minheap.begin();
                maxheap.insert(num);
                minheap.erase(minheap.begin());
            }
            
            res.push_back(*maxheap.rbegin());
        }
        
        return res;
    }
};

