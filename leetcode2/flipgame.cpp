class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        
        for(int i=0; i<int(s.size())-1; i++){
            if(s[i]=='+' && s[i+1]=='+'){
                s[i]='-';
                s[i+1]='-';
                res.push_back(s);
                //recover back
                s[i]='+';
                s[i+1]='+';
            }
        }
        
        return res;
    }
};