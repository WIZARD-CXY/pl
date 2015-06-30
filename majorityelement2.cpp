class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        
        int m=0,n=0; // m and n are candidates, note there are at most two candidates
        int mcount=0,ncount=0;// their count
        
        for(auto &a :nums){
            if(a==m){
                mcount++;
            }else if(a==n){
                ncount++;
            }else if(mcount==0){
                m=a;
                mcount=1;
            }else if(ncount==0){
                n=a;
                ncount=1;
            }else{
                mcount--;
                ncount--;
            }
        }
        
        //validate if m and n count > n/3
        mcount=ncount=0;
        for(auto &a :nums){
            if(a==m){
                mcount++;
            }else if(a==n){
                ncount++;
            }
        }
        
        if(mcount>nums.size()/3){
            res.push_back(m);
        }
        if(ncount>nums.size()/3){
            res.push_back(n);
        }
        
        return res;
    }
};