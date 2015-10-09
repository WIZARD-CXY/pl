class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        //use the binary search method
        
        int l=0;
        int r=num.size()-1;
        int mid=l;
        
        while(num[l]>num[r]){
            if(r-l==1){
                mid=r;
                break;
            }
            
            mid=l+((r-l)>>1);
            
            if(num[mid]>num[l]){
                //min exist in the right half
                l=mid;
            }else{
                r=mid;
            }
        }
        
        return num[mid];
    }
};
