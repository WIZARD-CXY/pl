class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int needCount[256]={0}; // needCount[i] record the i's need count
        int hasCount[256]={0}; //hasCount[i] record the i's current count 
        int count=0; // currently match count
        
        for(auto c : target){
            needCount[c]++;
        }
        
        int res=INT_MAX;
        
        int start=0;
        int end=0;
        
        int resstart=0;
        int resend=source.size()-1;
        
        while(end<source.size()){
            if(needCount[source[end]]==0){
                //don't need this char;
                end++;
                continue;
            }
            
            //need this char
            hasCount[source[end]]++;
            
            if(hasCount[source[end]]<=needCount[source[end]]){
                count++;
            }
            
            if(count==target.size()){
                //try to skip some extra char, move start forward
                
                while(start<end){
                    if(needCount[source[start]]==0){
                        start++; // not needed chars
                        continue;
                    }
                    
                    if(hasCount[source[start]]>needCount[source[start]]){
                        hasCount[source[start]]--;
                        start++;// extra chars
                        continue;
                    }else{
                        break;// can not move forward or will get source[start] 1 less
                    }
                }
                
                int tempwinlen=end-start+1;
                
                if(tempwinlen<res){
                    res=tempwinlen;
                    resstart=start;
                    resend=end;
                }
            }
            end++;
        }
        
        if(res==INT_MAX){
            return "";
        }
        return source.substr(resstart,res);
    }
};

