// search in step-th step with start index 'start', 
    void dfs(string &s, string ip, int start, int step){
        if(start==s.size() && step ==4){
            ip.resize(ip.size()-1);
            res.push_back(ip);
        }
        
        if(s.size()-start > (4-step)*3){
            return; //return early because there is too many extra bits
        }
        
        if(s.size()-start <(4-step)){
            return; //return early because there is not enough bits
        }
        
        int num=0;
        for(int i=start; i<start+3; i++){
            num=num*10+s[i]-'0';
            
            if(num<=255){
                // search forward
                ip+=s[i];   
                dfs(s, ip+'.', i+1, step+1);
            }
            
            if(num==0){
                break;// do not like leading 0
            }
        }
    }