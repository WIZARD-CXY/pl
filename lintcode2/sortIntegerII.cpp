class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        qsort(A, 0, A.size()-1);
    }
    
    void qsort(vector<int> &A, int l, int u){
        if (l>=u){
            return;
        }
        
        //use A[l] as pivot
        int t=A[l];
        int i=l;
        int j=u+1;
        
        // two-way scan
        while(true){
            do i++;while(i<=u && A[i]<t);
            do j--;while(A[j]>t);
            
            if(i>j){
                break;
            }
            swap(A, i, j);
        }
        swap(A,l,j);
        qsort(A,l,j-1);
        qsort(A,j+1,u);
    }
    
    void swap(vector<int> &A, int i, int j){
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    
};