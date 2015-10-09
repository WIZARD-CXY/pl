class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int spacecnt=0;
        
        for(int i=0; i<length; i++){
            if(string[i]==' '){
                spacecnt++;
            }
        }
        
        int newlen=length+spacecnt*2;
        
        int i=newlen-1;
        int j=length-1;
        
        for(; spacecnt>0; j--){
            if(string[j]!=' '){
                string[i--]=string[j];
            }else{
                string[i--]='0';
                string[i--]='2';
                string[i--]='%';
                spacecnt--;
            }
        }
        
        
        return newlen;
    }
};  
