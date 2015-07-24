class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n=A.size();
        
        int curReach=0;
        int maxIdx=0;
        
        int res=0;
        
        for(int i=0; i<A.size(); i++){
            if(A[i]==0 && maxIdx==i && i!=A.size()-1){
                //can't move forward to get to dst
                return -1;
            }
            
            if(curReach<i){
                curReach=maxIdx; //take a jump to maxIdx
                res++;
            }
            
            maxIdx=max(maxIdx,i+A[i]);
        }
        
        return res;
    }
};
