class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        
        if(n==0){
            return false;
        }
        //trim leading and trailing space
        int i=0;
        while(s[i]==' '){
            i++;
        }
        
        int j=s.size()-1;
        while(s[j]==' '){
            j--;
        }
        
        // is all space
        if(i>j){
            return false;
        }
        
        string ss=s.substr(i,j-i+1);
        
        // find e
        bool hasE=false;
        int epos=0;
        for(int i=0; i<ss.size(); i++){
            if(ss[i]=='e'){
                hasE=true;
                epos=i;
                break;
            }
        }
        
        if(hasE){
            //split over epos
            string s1=ss.substr(0,epos);
            string s2=ss.substr(epos+1);
            // s1 may have dot , but s2 must not have dot
            // check if s2 is valid sign number
            return isvalid(s1) && isSign(s2);
        }
        
        return isvalid(ss);
    }
    // determine whether a number is valid, may have '.'
    bool isvalid(string s){
        if(s.size()==0){
            return false;
        }
        
        if(s[0]=='+' || s[0]=='-'){
            s=s.substr(1);
        }
        if(s.size()==0){
            //only have +/-
            return false;
        }
        
        bool hasDot=false;
        int dotpos=0;
        
        // make sure we only have dot.
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                if(hasDot){
                    return false;
                }else{
                    hasDot=true;
                    dotpos=i;
                }
            }
        }
        
        // ss1.ss2
        if (hasDot){
            string ss1=s.substr(0,dotpos);
            string ss2=s.substr(dotpos+1);
            
            if(ss1.size()==0){
                return isPureNumber(ss2);
            }else if(ss2.size()==0){
                return isPureNumber(ss1);
            }
            return isPureNumber(ss1) && isPureNumber(ss2);
        }
        return isPureNumber(s);
        
    }
    
    bool isSign(string s){
        if(s[0]=='+' || s[0]=='-'){
            s=s.substr(1);
        }
        return isPureNumber(s);
    }
    bool isPureNumber(string s){
        if(s.size()==0){
            return false;
        }

        for(int i=0; i<s.size(); i++){
            if(s[i]>'9' || s[i]<'0'){
                return false;
            }
        }
        return true;
    }
};