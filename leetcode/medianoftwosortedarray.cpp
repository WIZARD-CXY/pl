class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        int total = m+n;
        
        if(total & 0x1){
            return find_kth(nums1,m,nums2,n,total/2+1);
        }else{
            return (find_kth(nums1,m,nums2,n,total/2)
            +find_kth(nums1,m,nums2,n,total/2+1))/2.0;
        }
        
    }
private:
    int find_kth(vector<int> nums1, int m, vector<int> nums2, int n, int k){
        //always let nums1's size smaller or equal to nums2
        if(m>n){
            return find_kth(nums2,n,nums1,m,k);
        }
        
        if(m==0){
            return nums2[k-1];
        }
        if(k==1){
            return min(nums1[0],nums2[0]);
        }
        
        //divide k into tow parts
        
        int mid1=min(k/2,m),mid2=k-mid1;
        
        vector<int>::iterator iter;
        if(nums1[mid1-1]<nums2[mid2-1]){
            iter=nums1.begin();
            for(int i=0; i<mid1; i++){
                iter++;
            }
            nums1.assign(iter,nums1.end());
            return find_kth(nums1,nums1.size(),nums2,nums2.size(),k-mid1);
        }else if (nums1[mid1-1]>nums2[mid2-1]){
            iter=nums2.begin();
            for(int i=0; i<mid2;i++){
                iter++;
            }
            nums2.assign(iter,nums2.end());
            return find_kth(nums1,nums1.size(),nums2,nums2.size(),k-mid2);
            
        }else{
            return nums1[mid1-1];
        }
    }
};