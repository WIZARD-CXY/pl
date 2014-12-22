class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count=n;
        for(int i=0; i<count; i++){
            if(A[i] == elem){
                
                for(int j=i; j<count-1; j++){
                    A[j]=A[j+1];
                }
                
                count--;
                i--;
            }
        }
        return count;
        
    }
};