class Solution {
public:
    int partition(vector<int>& nums, int p, int r){
        //choose the last one as pivot
        int i=p-1;
        
        for(int j=p; j<r; j++){
            if(nums[j]<nums[r]){
                swap(nums[++i],nums[j]);
            }
            
        }
        swap(nums[++i],nums[r]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        // to find kth largest is euqal to find (n+1-k)-th smallest
        return helper(nums, 0, n-1, n+1-k);
    }
    
    // find k-th smallese element
    int helper(vector<int>& nums, int low, int high,int k){
        int p=partition(nums,low,high);
            
        if(k==p-low+1){
            return nums[p];
        }else if(k<p-low+1){
            return helper(nums,low,p-1,k);
        }else{
            return helper(nums,p+1,high,k-(p-low+1));
        }
    }
};