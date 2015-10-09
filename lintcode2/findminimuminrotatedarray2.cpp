class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int l=0;
        int r=num.size()-1;
        
        int mid=l;
        
        while(num[l]>=num[r]){
            if(num[l]==num[r] && num[l]==num[mid]){
                // linear find
                return helper(num,l,r);
            }
            
            if(r-l==1){
                mid=r;
                break;
            }
            
            mid=l+((r-l)>>1);
            
            if(num[mid]>=num[l]){
                //min exist in the right side
                l=mid;
            }else{
                //min exist in the left side
                r=mid;
            }
        }
        
        return num[mid];
    }
    
    int helper(vector<int> &num, int l, int r){
        int min=INT_MAX;
        
        for(int i=l; i<=r; i++){
            if(num[i]<min){
                min=num[i];
            }
        }
        
        return min;
    }
};
