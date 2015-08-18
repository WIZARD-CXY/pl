class Solution {
public:
    string convert(string s, int numRows) {
        
        int i=0;
        vector<string> svec(numRows);
        
        while(i<s.size()){
            //fill the column
            for(int j=0 ; i<s.size()&&j<numRows; j++,i++){
                svec[j]+=s[i];
            }
            
            //fill the left-down to up-right
            for(int j=numRows-2; j>0 && i<s.size(); j--,i++){
                svec[j]+=s[i];
            }
        }
        
        string res;
        // row-wise fill the res;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<svec[i].size(); j++){
                res+=svec[i][j];
            }
        }
        return res;
        
    }
};