class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> v(nRows);
        
        int i=0;
        while(i<s.size()){
            //first fill the first column in the vector;
            
            for(int j=0; i<s.size() && j<nRows; j++,i++){
                v[j]+=s[i];
            }
            //then fill the slide in the vector
            for(int j=nRows-2; j>0 && i<s.size();j--,i++){
                v[j]+=s[i];
            }
        }
        
        string res;
        for(int i=0; i<nRows; i++){
            for(int j=0; j<v[i].size(); j++){
                res+=v[i][j];
            }
        }
        
        return res; 
    }
};