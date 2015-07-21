class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int count[26]={0};
        
        for(int i=0; i<A.size(); i++){
            int idx=(unsigned char)(A[i]-'A');
            count[idx]++;
        }
        
        for(int i=0; i<B.size(); i++){
            int idx=(unsigned char)(B[i]-'A');
            if((--count[idx])<0){
                return false;
            }
        }
        
        return true;
    }
};

