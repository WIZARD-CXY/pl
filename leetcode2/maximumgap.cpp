class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        
        if(n<2){
            return 0;
        }
        
        int maxnum=nums[0];
        int minnum=nums[0];
        
        for(auto n : nums){
            maxnum=max(maxnum,n);
            minnum=min(minnum,n);
        }
        
        if(maxnum==minnum){
            return 0;
        }
        // use n bucket for safety
        vector<vector<int> > bucket(n);
        //in case averagedist is 0 use ceil 
        int averagedist=ceil((maxnum-minnum)*1.0/(n-1));
        
        for(auto n :nums){
            int idx=(n-minnum)/averagedist;
            
            if(bucket[idx].empty()){
                bucket[idx].push_back(n);
                bucket[idx].push_back(n);
            }else{
                bucket[idx][0]=max(bucket[idx][0],n);
                bucket[idx][1]=min(bucket[idx][1],n);
            }
        }
        
        int res=INT_MIN;
        bool first=true;
        int pre;
        for(int i=0; i<bucket.size(); i++){
            if(bucket[i].empty()){
                continue;
            }
            
            // set the pre first
            if(first){
                first=false;
                pre=bucket[i][0];
                continue;
            }
            
            int tmp=bucket[i][1]-pre;
            pre=bucket[i][0];
            res=max(res,tmp);
        }
        
        return res;
    }
};