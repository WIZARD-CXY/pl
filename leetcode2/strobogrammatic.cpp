class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n=num.size();
        
        for(int i=0; i<n/2+1; i++){
            if(num[i]=='2' || num[i]=='3' || num[i] == '4' || num[i]=='5'|| num[i]=='7'){
                return false;
            }else if(num[i]=='9' && num[n-i-1]!='6'){
                return false;
            }else if(num[i]=='6' && num[n-i-1]!='9'){
                return false;
            }else if(num[i]=='8' || num[i]=='1' || num[i]=='0'){
                 if(num[i]!=num[n-i-1]){
                     return false;
                 }
            }
        }
        
        return true;
    }
};