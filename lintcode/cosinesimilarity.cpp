class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int asize=A.size();
        int bsize=B.size();
        
        if(asize==0 || bsize==0){
            return 2.0000;
        }
        
        double ab=0;
        
        for(int i=0; i<asize; i++){
            ab+=A[i]*B[i];
        }
        
        double aa=0.0;
        
        for(int i=0; i<asize; i++){
            aa+=A[i]*A[i];
        }
        
        if(aa==0){
            return 2.0000;
        }
        
        double bb=0.0;
        
        for(int i=0; i<bsize; i++){
            bb+=B[i]*B[i];
        }
        
        if(bb==0){
            return 2.0000;
        }
        
        return ab/sqrt(aa)/sqrt(bb);
    }
};

