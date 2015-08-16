class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        int total=m+n;
        if(total&1){
            return findKth(nums1.begin(),m,nums2.begin(),n,(total+1)/2);
        }else{
            return (findKth(nums1.begin(),m,nums2.begin(),n,total/2)+findKth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
        }
    }
    
    double findKth(vector<int>::iterator it1,int m, vector<int>::iterator it2,int n,int k){
        if(m>n){
            return findKth(it2,n,it1,m,k);
        }
        
        if(m==0){
            return *(it2+k-1);
        }
        if(k==1){
            return min(*it1,*it2);
        }
        
        int mid1=min(k/2,m);
        int mid2=k-mid1;
        
        if(*(it1+mid1-1)==*(it2+mid2-1)){
            return *(it1+mid1-1);
        }else if(*(it1+mid1-1)>*(it2+mid2-1)){
            //safely remove mid2-1
            return findKth(it1,m,it2+mid2,n-mid2,k-mid2);
        }else{
            return findKth(it1+mid1,m-mid1,it2,n,k-mid1);
        }
    }
};