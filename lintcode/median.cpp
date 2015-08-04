class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        
        int k=(n+1)/2;
        
        return findKthsmallest(nums, 0, n-1, k);
    }
    
    int findKthsmallest(vector<int> &nums, int l, int r, int k){
        int  p=partition(nums,l,r);
        
        //left array plus pivot has p-l+1 element 
        if(p-l+1==k){
            return nums[p];
        }else if(p-l+1 >k){
            //find kth smallest in left array
            return findKthsmallest(nums,l,p-1,k);
        }else{
            //find in right array
            return findKthsmallest(nums,p+1,r,k-(p-l+1));
        }
    }
    int partition(vector<int> &nums, int l, int r){
        int i=l-1;
        
        // use nums[r] as pivot
        for(int j=l; j<r; j++){
            if(nums[j]<nums[r]){
                swap(nums[++i],nums[j]);
            }
        }
        
        swap(nums[++i],nums[r]);
        
        return i;
        
    }
};

