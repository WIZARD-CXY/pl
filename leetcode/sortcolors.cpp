class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,blueIdx=nums.size()-1;
        
        // 0 to red-1 is all red 
        // red to blueIdx is all white
        // blueIdx+1 to nums.size()-1 is all blue
        
        for(int i=0; i<blueIdx+1;){
            if(nums[i]==0){
                swap(nums[i++],nums[red++]);
            }else if(nums[i]==2){
                swap(nums[i],nums[blueIdx--]);
            }else{
                i++;
            }
        }
        
    }
};