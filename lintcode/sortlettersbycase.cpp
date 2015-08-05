class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int i=-1;
        
        //letters[0..i] lowercase [i+1..j-1] upper case
        for(int j=0; j<letters.size(); j++){
            if(islow(letters[j])){
                swap(letters[++i],letters[j]);
            }
        }
        
    }
    bool islow(char c){
        if(c>='a' && c<='z'){
            return true;
        }
        return false;
    }
};

