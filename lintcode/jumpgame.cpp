class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int maxIdx=0;
        
        for(int i=0; i<A.size();i++){
            maxIdx=max(i+A[i],maxIdx);
            if(maxIdx>=A.size()-1){
                return true;
            }
            if(A[i]==0 && maxIdx==i){
                return false;
            }
        }
        
        return true;
    }
};

