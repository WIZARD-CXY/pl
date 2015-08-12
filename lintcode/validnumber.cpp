class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int i=0;
        int len=s.size();
        
        //deal with leading space
        while(i<len && s[i]==' '){
            i++;
        }
        if(i==len){
            return false;
        }
        
        //deal with trailing space
        int j=len-1;
        
        while(j>=0 && s[j]==' '){
            j--;
        }
        
        if(j<i){
            return false;
        }
        
        string ss=s.substr(i,j-i+1);
        
        
        //find e pos
        int epos=0;
        bool hasE=false;
        
        for(int i=0; i<ss.size(); i++){
            if(ss[i]=='e'){
                hasE=true;
                epos=i;
                break;
            }
        }
        
        if(hasE){
            //split over e pos
            
            string s1=ss.substr(0,epos);
            string s2=ss.substr(epos+1);
            
            //s1 may have dot but s2 must not have dot
            return isvalid(s1) && isSign(s2);
        }
        
        return isvalid(ss);
    }
    
    bool isvalid(string &s){
        if(s.size()==0){
            return false;
        }
        
        bool hasdot=false;
        int dotpos=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='.'){
                hasdot=true;
                dotpos=i;
                break;
            }
        }
        
        
        if(hasdot){
            //s1.s2
            string s1=s.substr(0,dotpos);
            string s2=s.substr(dotpos+1);
            
            if(s1.size()==0){
                return isPureNumber(s2);
            }
            
            return isSign(s1)&&isPureNumber(s2);
        }
        return isSign(s);
    }
    
    bool isSign(string &s){
        if(s.size()==0){
            return false;
        }
        int i=0;
        if(s[i]=='+' || s[i]=='-'){
            i++;
        }
        
        return isPureNumber(s.substr(i));
    }
    
    bool isPureNumber(string s){
        if(s.size()==0){
            return false;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i]>'9' || s[i] <'0'){
                return false;
            }
        }
        
        return true;
    }
};
