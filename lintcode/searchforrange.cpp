class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        if(A.size()==0){
            return vector<int>{-1,-1};
        }
        int lower=lower_bound(A,target);
        int upper=upper_bound(A,target);
        
        if(A[lower]!=target){
            return vector<int>{-1,-1};
        }else{
            return vector<int>{lower,upper-1};
        }
        
    }
    int lower_bound(vector<int> &A, int target){
        int l=0;
        int r=A.size();
        
        while(l<r){
            int m=l+((r-l)>>1);
            
            if(A[m]>=target){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        return l;
    }
    
    int upper_bound(vector<int> &A, int target){
        int l=0;
        int r=A.size();
        
        while(l<r){
            int m=l+((r-l)>>1);
            
            if(A[m]>target){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        return l;
    }
    
};
