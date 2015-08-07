class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        int radix[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string sym[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res="";
        int i=0;
        
        while(n){
            int count = n/radix[i];
            n=n%radix[i];
            
            while(count--){
                res+=sym[i];
            }
            i++;
        }
        return res;
    }
};
