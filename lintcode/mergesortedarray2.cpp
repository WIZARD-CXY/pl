class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> res;
        int asize=A.size();
        int bsize=B.size();
        int p=0;
        int q=0;
        
        while(p<asize || q<bsize){
            if(q>=bsize || (p<asize && A[p]<=B[q])){
                res.push_back(A[p++]);
            }else{
                res.push_back(B[q++]);
            }
        }
        return res;
    }
};
