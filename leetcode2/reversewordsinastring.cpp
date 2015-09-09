class Solution {
public:
    void reverseWords(string &s) {
        int i=0;
        
        //remove leading and trailint space
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        
        int j=s.size()-1;
        while(j>=0 && s[j]==' '){
            j--;
        }
        
        s=s.substr(i,j-i+1);
        reverse(s,0,s.size()-1);
        
        int p=0,q=0;
        
        while(q<s.size()){
            while(q<s.size() && s[q]!=' '){
               q++;
            }
            reverse(s,p,q-1);
            
            bool first=true;
            while(q<s.size() && s[q]==' '){
                if(!first){
                    //trim extra space
                    s.erase(s.begin()+q);
                }else{
                    q++;
                    first=false;
                }
            }
            p=q;
        }
        
    }
    void reverse(string &s ,int p, int q){
        while(p<q){
            swap(s[p++],s[q--]);
        }
    }
};