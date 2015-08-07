class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int char2int(char c){
        switch (c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string& s) {
        // Write your code 
        int res=0;
        
        int sum=char2int(s.back());
        
        // tail to head travesal 
        for(int i=s.size()-1; i>=1; i--){
            if(char2int(s[i])>char2int(s[i-1])){
                sum-=char2int(s[i-1]);
            }else{
                sum+=char2int(s[i-1]);
            }
        }
        
        return sum;
    }
};
