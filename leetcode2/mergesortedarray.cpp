class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=m-1;
        int q=n-1;
        int last=m+n-1;
        
        while(p>=0 || q>=0){
            if(q<0 || (p>=0 && nums1[p]>nums2[q])){
                nums1[last--]=nums1[p--];
            }else{
                nums1[last--]=nums2[q--];
            }
        }
    }
};