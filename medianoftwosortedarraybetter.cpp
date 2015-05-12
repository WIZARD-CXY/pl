class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        int total = m+n;
        
        if(total & 0x1){
            return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
        }else{
            return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2)
            +find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
        }
        
    }
private:
    int find_kth(vector<int>::iterator nums1, int m, vector<int>::iterator nums2, int n, int k){
        //always let nums1's size smaller or equal to nums2
        if(m>n){
            return find_kth(nums2,n,nums1,m,k);
        }
        
        if(m==0){
            return *(nums2+k-1);
        }
        if(k==1){
            return min(*nums1,*nums2);
        }
        
        //divide k into tow parts
        
        int mid1=min(k/2,m),mid2=k-mid1;
        
        vector<int>::iterator iter;
        if(*(nums1+mid1-1)<*(nums2+mid2-1)){
            return find_kth(nums1+mid1,m-mid1,nums2,n,k-mid1);
        }else if (*(nums1+mid1-1)>*(nums2+mid2-1)){
            return find_kth(nums1,m,nums2+mid2,n-mid2,k-mid2);
            
        }else{
            return nums1[mid1-1];
        }
    }
};