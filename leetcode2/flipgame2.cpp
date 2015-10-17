class Solution {
public:
    string ss;
    bool canWin(string s) {
        ss=s;
        
        return canwin();
    }
    
    bool canwin(){
        for(int i=0; i<int(ss.size())-1; i++){
            if(ss[i]=='+' && ss[i+1] =='+'){
                ss[i]='-';
                ss[i+1]='-';
                
                bool res=canwin();
                // back tracking
                ss[i]='+';
                ss[i+1]='+';
                //if component don't win I win
                if(!res){
                    return true;
                }
            }
        }
        return false;
    }
};