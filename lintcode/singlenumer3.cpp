class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> res;
        if(A.size()==0){
            return res;
        }
        int temp=0;
        
        for(auto a : A){
            temp^=a;
        }
        //temp is at least one bit is 1, 0 index based
        
        int idx=findfirst1(temp);
        int num1=0;
        int num2=0;
        
        //split into two groups
        for(auto a : A){
            if(a&(1<<idx)){
                num1^=a;
            }else{
                num2^=a;
            }
        }
        return vector<int>{num1,num2};

    }
    
    int findfirst1(int num){
        int i=0;
        
        for(int i=0; i<32; i++){
             if(n & (1<<i)){
                 return i;
             }
        }
        
        if(i==32){
            return -1;
        }
    }
};
