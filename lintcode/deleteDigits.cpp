class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        
        while(k--){
            //delete the first decreasing element
            //every step is optimal
            int i=0;
            while(i<A.size()-1 && A[i]<= A[i+1]){
                i++;
            }
            A.erase(i,1);
        }
        
        int i=0;
        //delete leading 0
        while(i<A.size() && A[i]=='0'){
            i++;
        }
        
        return A.substr(i);
    }
};

