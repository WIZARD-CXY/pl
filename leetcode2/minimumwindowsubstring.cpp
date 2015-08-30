class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> has;

        int count=0;//already has char count
        
        //count every char's frequences
        for(int i=0; i<t.size(); i++){
            need[t[i]]++;
        }
        
        int start=0;
        int end=0;
        int resstart=0;
        int resend=s.size()-1;
        
        int min=INT_MAX;
        
        while(end<s.size()){
            // don't need 
            if(need[s[end]]==0){
                end++;
                continue;
            }
            
            // need this char
            has[s[end]]++;
            if(has[s[end]]<=need[s[end]]){
                // do not have enough
                count++;
            }
            
            if(count==t.size()){
                //have got all the needed char
                //try to make the size smaller
                while(start<end){
                    if(need[s[start]]==0){
                        //do not need this char
                        start++;
                        continue;
                    }
                    
                    if(has[s[start]]>need[s[start]]){
                        has[s[start]]--;
                        start++;
                        continue;
                    }
                    
                    if(has[s[start]]==need[s[start]]){
                        break;
                    }
                }
                
                if(end-start+1<min){
                    min=end-start+1;
                    resend=end;
                    resstart=start;
                }
            }
            end++;
        }
        
        if(min==INT_MAX){
            return "";
        }
        
        return s.substr(resstart,resend-resstart+1);
        
    }
};