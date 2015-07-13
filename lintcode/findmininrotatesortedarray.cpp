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
        
        while(num[l]>=num[r]){
            int mid = (l+r)/2;
            if(r-l==1){
                return num[r];
            }
            
            if(num[mid]==num[l] && num[l]==num[r]){
                return helper(num,l,r);
            }
            
            if(num[mid]>=num[l]){
                l=mid;
            }else if(num[mid]<=num[r]){
                r=mid;
            }
        }
        
        return num[l];
    }
    
    int helper(vector<int> &num,int l, int r){
        int minVal=INT_MAX;
        
        for(int i=l; i<=r; i++){
            minVal=min(minVal,num[i]);
        }
        
        return minVal;
    }
};
