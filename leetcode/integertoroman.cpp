class Solution {
public:
    string intToRoman(int num) {
        int radix[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res="";
        
        for(int i=0; num>0; i++){
            int count = num/radix[i];
            num = num%radix[i];
            
            while(count>0){
                res+=symbol[i];
                count--;
            }
            
        }
        
        return res;
        
    }
};