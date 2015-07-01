class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int blankCount = 0;  // indicate the blank number
        for ( int i = 0; i < length; i++) {
            if(string[i] == ' '){
                blankCount++;
            }
        }
        
        int res = blankCount*2+length;
        int temp = res-1;
        
        for (int i = length-1; i >= 0 && blankCount>0; i--){
            if(string[i]!=' '){
                string[temp--]=string[i];
            }else{
                //meet the ' '
                string[temp--]='0';
                string[temp--]='2';
                string[temp--]='%';
                blankCount--;
            }
        }
        
        return res;
    }
};  
