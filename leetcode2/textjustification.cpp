class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        if(words.size()==0){
            return res;
        }
        
        int sum=words[0].size();
        int start=0;
        
        for(int i=1; i<words.size(); i++){
            if(sum+words[i].size()+1>maxWidth){
                //overflow
                string line=addSpace(words,start,i,maxWidth,sum);
                res.push_back(line);
                start=i;
                sum=words[i].size();
            }else{
                sum+=words[i].size()+1;
            }
        }
        
        //add last line
        string lastline=addSpaceLastline(words,start,words.size(),maxWidth);
        res.push_back(lastline);
 
        return res;
    }
    
    string addSpaceLastline(vector<string> &words, int start, int end, int maxWidth){
        string ret=words[start];
        for(int i=start+1; i<end; i++){
            ret+=' '+words[i];
        }
        
        if(ret.size()<maxWidth){
            ret.append(maxWidth-ret.size(),' ');
        }
        return ret;
    }
    
    string addSpace(vector<string> &words, int start, int end, int maxWidth, int sum){
        string ret="";
        
        int count=end-start;
        int extraSpace=maxWidth-sum;
        
        if(count==1){
            ret+=words[start];
            ret.append(extraSpace,' ');
        }else{
            int averagespace=extraSpace/(count-1);
            int remainerspace=extraSpace%(count-1);
            
            for(int i=start; i<end-1; i++){
                ret+=words[i];
                //append space 
                
                ret.append(averagespace+1,' ');
                if(remainerspace){
                    ret.append(1,' ');
                    remainerspace--;
                }
            }
            
            ret+=words[end-1];
        }
        
        return ret;
    }
};