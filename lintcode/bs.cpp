class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        long long l=0;
        long long r=array.size();
        
        while(l<r){
            long long m=(l+r)>>1;
            
            if(array[m]>=target){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        if(array[l]==target){
            return l;
        }else{
            return -1;
        }
        
    }
};
