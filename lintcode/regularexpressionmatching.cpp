class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(*p==0){
            return *s==0;
        }
        
        if(*(p+1)!='*'){
            //p[1]== 0 or alphabet or '.'
            if(*p==*s || *p=='.' && *s!=0){
                return isMatch(s+1,p+1);
            }else{
                return false;
            }
        }else{
            //*(p+1)=='*'
            while(*p==*s || *p=='.' && *s!=0){
                //* match s 0/1/2... chars 
                if(isMatch(s++, p+2)){
                    return true; 
                }
                     
            }
            //not match 
            return isMatch(s,p+2);
        }
    }
};
