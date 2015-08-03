class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        
        int end=s.size()-1;
        
        //remove trailing ' '
        while(end>=0 && s[end]==' '){
            end--;
        }
        
        if(end==-1){
            //all ' '
            return 0;
        }
        
        int start=end;
        while(start>=0 && s[start]!=' '){
            start--;
        }
        
        return end-start;
        
    }

};
