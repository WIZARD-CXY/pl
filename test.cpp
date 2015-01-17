#include<iostream>
#include<string>

#include<vector>

#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

int stoi(string s){
    int res=0;
    int sign=1;

    for(int i=0; i<s.size(); i++){
        if(i==0 && s[i] == '-'){
            sign=-1;
        }else{
            res=res*10+s[i]-'0';
        }

    }
    return sign*res;
}

int evalRPN(vector<string> &tokens) {
        stack<int> ss;
        int temp1,temp2;
        
        for(int i=0; i<tokens.size(); i++){
            
            if(ss.empty() || (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")){
                ss.push(stoi(tokens[i]));
            }else if(tokens[i] == "+"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp1+temp2);
            }else if(tokens[i] == "-"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp2-temp1);
            }else if(tokens[i] == "*"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp1*temp2);
            }else if(tokens[i] == "/"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp2/temp1);
            }
            
        }
        return ss.top();
        
    }


int main(){
    std::vector<string> v;
    v.push_back("6");
    v.push_back("3");
    v.push_back("/");
    cout<<evalRPN(v)<<endl;
    cout<<stoi("012345")<<endl;

}