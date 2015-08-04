class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int n=A.size();
        if(n==1){
            return 1;
        }
        long long res=1;
        long long pos=2;
        long long factor=1;
        map<int,int> num2cnt;
        num2cnt[A.back()]++;
        
        for(int i=n-2;i>=0; i--){
            num2cnt[A[i]]++;
            
            for(auto kv : num2cnt){
                // find all small than A[i] element
                if(kv.first>=A[i]){
                    break;
                }
                
                res+=factor*kv.second/num2cnt[A[i]];
            }
            
            factor=factor*pos/num2cnt[A[i]];
            pos++;
        }
        
        return res;
    }
};
