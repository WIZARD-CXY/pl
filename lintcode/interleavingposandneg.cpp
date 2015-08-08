class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int poscnt=0;
        int negcnt=0;
        
        for(auto a : A){
            if(a<0){
                negcnt++;
            }else{
                poscnt++;
            }
        }
        
        int posidx=0,negidx=1;
        
        if(negcnt>poscnt){
            posidx=1;
            negidx=0;
        }
        
        while(posidx<A.size() && negidx<A.size()){
            while(posidx<A.size() && A[posidx]>0){
                posidx+=2;
            }
            
            while(negidx<A.size() && A[negidx]<0){
                negidx+=2;
            }
            if(negidx<A.size() && posidx<A.size()){
                swap(A[negidx],A[posidx]);
            }
        }
    }
};
