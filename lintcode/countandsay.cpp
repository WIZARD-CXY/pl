class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string res;
        
        if(n==0){
            return res;
        }
        
        res="1";
        
        for(int i=2; i<=n; i++){
            string temp=res;
            res="";
            char pre=temp[0];
            int count=1;
            
            for(int j=1; j<temp.size(); j++){
                if(temp[j]!=pre){
                    res+=to_string(count)+pre;
                    pre=temp[j];
                    count=1;
                }else{
                    count++;
                }
            }
            // append the last one
            res+=to_string(count)+pre;
        }
        
        return res;
    }
};
