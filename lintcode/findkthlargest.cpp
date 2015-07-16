class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     
    int partition(vector<int> &nums, int l, int r){
        int i=l-1;
        
        for(int j=l; j<r; j++){
            if(nums[j]<nums[r]){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[++i],nums[r]);
        return i;
    }
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        // find kth largest equals to find nums.size()-k+1 th smallest
        return findKthsmallest(nums,0,nums.size()-1,nums.size()-k+1);
    }
    
    int findKthsmallest(vector<int> &nums, int l, int r, int k){
        int p=partition(nums,l,r);
        
        if(p-l+1==k){
            return nums[p];
        }else if(p-l+1 >k){
            //find in the left side
            return findKthsmallest(nums,l,p-1,k);
        }else{
            // find in the left side
            return findKthsmallest(nums,p+1,r,k-(p-l+1));
        }
    }
};
