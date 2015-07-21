class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        multiset<int> minheap,maxheap;
        vector<int> res;
        if(k>nums.size() || k==0){
            return res;
        }
        
        //init the minheap and and max heap with first k element
        for(int i=0; i<k; i++){
            maxheap.insert(nums[i]);
        }
        //move the larger half to the min heap then
        while(maxheap.size()>(k+1)/2){
            int tmp=*maxheap.rbegin();
            minheap.insert(tmp);
            maxheap.erase(maxheap.find(tmp));
        }
        
        res.push_back(*maxheap.rbegin());
        for(int i=k; i<nums.size(); i++){
            // delete the leftmost element nums[i-k] from heap
            if(nums[i-k]<=res.back()){
                //in the maxheap
                maxheap.erase(maxheap.find(nums[i-k]));
            }else{
                // in the minheap
                minheap.erase(minheap.find(nums[i-k]));
            }
            
            //insert nums[i] into heaps
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

