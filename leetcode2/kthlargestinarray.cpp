class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        
        //kth larget is n-k+1 th smallest
        //find it in the array
        
        return findKthSmallest(nums,n-k+1,0,n-1);
    }
    
    int findKthSmallest(vector<int> &nums,int k, int l, int r){
        int n=nums.size();
        
        int p=partition(nums,l,r);
        
        if(p-l+1==k){
            return nums[p];
        }else if(p-l+1 >k){
            //find in the left
            return findKthSmallest(nums,k,l,p-1);
        }else{
            return findKthSmallest(nums,k-p+l-1,p+1,r);
        }
    }
    
    int partition(vector<int> &nums, int l, int r){
        int i=l-1;
        
        for(int j=l;j<r; j++){
            if(nums[j]<nums[r]){
                swap(nums[j],nums[++i]);
            }
        }
        swap(nums[++i],nums[r]);
        
        return i;
    }
};