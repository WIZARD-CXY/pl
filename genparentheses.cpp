class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if(n>0){
            gen("",n,n);
        }
        
        return res;
    }
    // l indicate how many '(' left
    // r indicate how many ')' left
    void gen(string s, int l, int r){
        if(l==0 && r==0){
            res.push_back(s);
        }
        
        if(l>0){
            gen(s+'(',l-1,r);
        }
        
        if(r>0 && l<r){
            gen(s+')',l,r-1);
        }
    }
};