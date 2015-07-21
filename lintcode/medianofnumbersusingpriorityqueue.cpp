class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    struct cmp{
        bool operator() (const int &a, const int &b){
            return a>b;
        }
    };
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int,vector<int>, cmp> minheap;
        priority_queue<int> maxheap;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            if(maxheap.empty() || nums[i]<maxheap.top()){
                maxheap.push(nums[i]);
            }else{
                minheap.push(nums[i]);
            }
            
            // always keep maxheap.size() == minheap.size()
            // or just one element larger
            // then *maxheap.rbegin() is median
            if(maxheap.size() > minheap.size()+1){
                int num=maxheap.top();
                minheap.push(num);
                maxheap.pop();
                
            }else if(maxheap.size() < minheap.size()){
                int num=minheap.top();
                maxheap.push(num);
                minheap.pop();
            }
            
            res.push_back(maxheap.top());
        }
        
        return res;
    }
};

