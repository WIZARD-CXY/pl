class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        // nums has no dups
        int n=num.size();
        
        int l=0;
        int r=n-1;
        int mid=l;
        
        while(num[l]>num[r]){
            if(r-l==1){
                mid=r;
                break;
            }
            
            mid=(l+r)>>1;
            
            if(num[mid]>=num[l]){
                l=mid;
            }else if(num[mid]<=num[r]){
                r=mid;
            }
            
        }
        return num[mid];
    }
};
