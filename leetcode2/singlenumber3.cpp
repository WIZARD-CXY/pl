class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp=0;
        
        for(auto num : nums){
            tmp^=num;
        }
        
        int diffpos=0;
        for(int i=0; i<32; i++){
            if(tmp&(1<<i)){
                diffpos=i;
                break;
            }
        }
        
        vector<int> groupa;
        vector<int> groupb;
        
        for(auto num :nums){
            if(num&(1<<diffpos)){
                groupa.push_back(num);
            }else{
                groupb.push_back(num);
            }
        }
        
        int a=0;
        
        for(auto num: groupa){
            a^=num;
        }
        
        int b=0;
        
        for(auto num: groupb){
            b^=num;
        }
        
        return {a,b};
    }
};