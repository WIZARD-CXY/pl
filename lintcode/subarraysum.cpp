class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int n=nums.size();
        vector<int> res;
        // sums[i] contains sum of [0..i)
        vector<int> sums(n+1,0);
        
        sums[0]=0;
        // mm[i] stores sums[i]'s index
        unordered_map<int,int> mm;
        mm[0]=0;
        
        for(int i=1; i<=nums.size(); i++){
            sums[i]=sums[i-1]+nums[i-1];
            auto it=mm.find(sums[i]);
            if(it!=mm.end()){
                res.push_back(it->second);
                res.push_back(i-1);
                return res;
            }else{
                mm[sums[i]]=i;
            }
        }
         
        return res;
    }
};
