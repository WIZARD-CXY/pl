class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
     // not fully ac
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int n=nums.size();
        //sums[i] records sum of [0..i)
        vector<int> sums(n+1,0);
        sums[0]=0;
        vector<int> res;
        
        unordered_map<int,int> mm;
        for(int i=1; i<=n; i++){
            sums[i]=sums[i-1]+nums[i-1];
            mm[sums[i]]=i;
        }
        
        sort(sums.begin(),sums.end());
        int minidx=0;
        int maxidx=0;
        int dist=INT_MAX;
        for(int i=1;i<sums.size(); i++){
            if(sums[i]-sums[i-1]<dist){
                dist=sums[i]-sums[i-1];
                minidx=min(mm[sums[i]],mm[sums[i-1]]);
                maxidx=max(mm[sums[i]],mm[sums[i-1]])-1;
            }
        }
        res.push_back(minidx);
        res.push_back(maxidx);
        
        return res;
    }
};

