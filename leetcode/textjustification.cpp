class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        //indicate the start index of words in a line
        int start=0;
        
        //len indicate the current length, the first word len does not including leading space
        //other word will plus a space leading this word
        int len=words[0].size(); 
        
        for(int i=1; i<words.size(); i++){
            if(len+words[i].size()+1>maxWidth){
                // add words[i] will overflow
                // add current line to res
                string temp=addSpace(words,start,i,len,maxWidth);
                res.push_back(temp);
                // start a new line
                start=i;
                len=words[i].size();
            }else{
                len+=words[i].size()+1;
            }
        }
        //add last line
        string temp=addSpaceLastline(words,start,words.size(),maxWidth,len);
        res.push_back(temp);
        return res;
        
    }
    string addSpaceLastline(vector<string> &words, int start, int end, int maxWidth, int len){
        string temp=words[start];
        for(int i=start+1; i<end; i++){
            temp+=" "+words[i];
        }
        //append with extra space
        if(temp.size()<maxWidth){
            temp.append(maxWidth-temp.size(),' ');
        }
        
        return temp;
        
    }
    // add space evenly to [start,end)
    string addSpace(vector<string> &words, int start, int end, int len, int maxWidth){
       string temp="";
       int extraSpace=maxWidth-len;
       int count=end-start;
       
       if(count==1){
           temp=words[start];
           temp.append(extraSpace,' ');
       }else{
           int averSpace=extraSpace/(count-1);
           int remainer=extraSpace%(count-1);
           for(int i=start; i<end-1; i++){
               temp+=words[i];
               temp.append(averSpace+1,' ');
               if(remainer){
                   temp.append(1,' ');
                   remainer--;
               }
           }
           temp+=words[end-1];
       }
       
       return temp;
    }
};kb