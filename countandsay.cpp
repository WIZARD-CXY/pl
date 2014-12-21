class Solution {
public:
    string countAndSay(int n) {
        string res,temp;
        if(n==0){
            return res;
        }
        char curC;
        res="1";
        int count;
        
        for(int i=1; i<n; i++){
            temp=res;
            curC=temp[0];
            res="";
            count=1;
            
            for(int j=1; j<temp.size(); j++){
                if(curC == temp[j]){
                    count++;
                } else{
                    res=res+(char)(count+'0')+curC;
                    curC=temp[j];
                    count=1;
                }
            }
           res=res+(char)(count+'0')+curC;
        }
        
        return res;
    }
};