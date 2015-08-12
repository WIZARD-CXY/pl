class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int m=A.size();
        int n=B.size();
        
        int total=m+n;
        
        if(total &1){
            //total odd element
            return findKthsmall(A.begin(),m,B.begin(),n,total/2+1);
        }else{
            return (findKthsmall(A.begin(),m,B.begin(),n,total/2)+findKthsmall(A.begin(),m,B.begin(),n,total/2+1))/2.0;
        }
    }
    
    int findKthsmall(vector<int>::iterator ita, int m, vector<int>::iterator itb, int n, int k){
        if(m>n){
            //always have m smaller or equal to n
            return findKthsmall(itb,n,ita,m,k);
        }
        
        if(m==0){
            return *(itb+k-1);
        }
        
        if(k==1){
            return min(*ita,*itb);
        }
        
        //divide k into 2 parts
        int mid1=min(m,k/2),mid2=k-mid1;
        
        if(*(ita+mid1-1)==*(itb+mid2-1)){
            return *(ita+mid1-1);
        }else if(*(ita+mid1-1)>*(itb+mid2-1)){
            //safely remove mid2 element in B
            return findKthsmall(ita,m,itb+mid2,n-mid2,k-mid2);
        }else{
            //safely remove mid1 element in A
            return findKthsmall(ita+mid1,m-mid1,itb,n,k-mid1);
        }
    }
};

