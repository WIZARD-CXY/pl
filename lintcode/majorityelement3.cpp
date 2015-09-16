class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        // maintain k-1 candidate in map
        // mm[i]=j , means i number is candidate and have count j
        unordered_map<int,int> mm;
        
        for(int i=0; i<nums.size(); i++){
            if(mm.find(nums[i])!=mm.end()){
                // nums i is already a can
                mm[nums[i]]++;
            }else{
                // a little trick new element set to 2 in case following all minus one
                mm[nums[i]]=2;
                if(mm.size()==k){
                    //need reduce to k-1 candidate, every candicate count--
                    for(auto iter = mm.begin(); iter!=mm.end();){
                        if((--(iter->second))==0){
                            iter=mm.erase(iter);
                        }else{
                            iter++;
                        }
                    }
                }
            }
        }
        
        int res;
        int maxcount=0;
        unordered_map<int,int> newmm;
        
        //find the maxcount in the candidate map
        for(auto num : nums){
            // if it is a can
            if(mm.find(num)!=mm.end()){
                if(newmm.find(num)!=newmm.end()){
                    newmm[num]++;
                }else{
                    newmm[num]=1;
                }
                
                if(newmm[num]>maxcount){
                    maxcount=newmm[num];
                    res=num;
                }
                
            }
        }
        
        return res;
    }
};