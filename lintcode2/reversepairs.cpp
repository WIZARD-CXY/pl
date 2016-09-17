class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long res=0;
    long long reversePairs(vector<int>& A) {
        // Write your code here
       
        int n=A.size();
        vector<int> t(n,0);
        
        helper(A,0,n,t);
        
        return res;
    }
    
    void helper(vector<int> &A, int x, int y, vector<int>& t){
        if(y-x>1){
            int m=x+((y-x)>>1);
            helper(A,x,m,t);
            helper(A,m,y,t);
            
            //merge
            int p=x,i=x,q=m;
            
            while(p<m || q<y){
                if(q>=y || (p<m && A[p]<=A[q])){
                    t[i++]=A[p++];
                }else{
                    // when use a right element to fill in the t,
                    // the A[q] is smaller than all the A[x] where x is [p,m)
                    // so in terms of A[q], there is m-p reverse pairs
                    res+=(m-p);
                    t[i++]=A[q++];
                }
            }
            
            for(int i=x; i<y; i++){
                A[i]=t[i];
            }
        }
        
    }
};