class Solution {
public:
    string minWindow(string s, string t) {
        int tlen=t.size();
        int slen=s.size();
        
        // st
        if(tlen==0 || slen<tlen){
            return "";
        }
        int need[256]={0};//record the needed char's number
        int has[256]={0};// record the current get char's number
        
        for(int i=0; i<t.size(); i++){
            need[t[i]]++;
        }
        
        int minWinlen=INT_MAX;
        int count=0;//currently ready number
        
        int start=0;
        int end=0;
        int winstart=0;
        int winend=slen-1;
        
        for(;end<slen;end++){
            // current s[end] is not needed, move forward
            if(need[s[end]]==0){
                continue;
            }
            
            // just found one needed char
            has[s[end]]++;
            
            //update the total number of characters found(aaa only counts 2 for aa in T)  
            if(has[s[end]]<=need[s[end]]){
                count++;
            }
            
            // if all the chars needed are found
            if(count==tlen){
                //a window from start to end
                //try to move start pointer to get a smaller window
                while(start<end){
                    //skip unwanted char
                    if(need[s[start]]==0){
                        start++;
                        continue;
                    }
                    
                    //skip extra redundant char
                    if(has[s[start]]>need[s[start]]){
                        has[s[start]]--;
                        start++;
                        continue;
                    }else{
                        break;
                    }
                }
                
                int tempWinlen=end-start+1;
                
                if(tempWinlen<minWinlen){
                    minWinlen=tempWinlen;
                    winstart=start;
                    winend=end;
                }
            }
        }
        
        if(minWinlen==INT_MAX){
            // not contain any result, retrun ""
            return "";
        }
        return s.substr(winstart,winend-winstart+1);
        
    }
};