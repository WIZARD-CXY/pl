#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

string simplifyPath(string path) {
    stack<string> ss;
    
    for(int i=0; i<path.size();){

        while(i<path.size() && path[i]=='/'){
            i++;
        }
        if(i==path.size()) break;
        
        string s=""; // record the content between two consecutive '/'
        
        while(i<path.size() && path[i]!='/'){
            s=s+path[i];
            i++;
        }
        
        if(s==".." && !ss.empty()){
            ss.pop();
        }else if ( s!="." && s !=".."){
            ss.push(s);
        }
    }

        
    //just root path
    if(ss.empty()){
        return "/";
    }
    
    string res;
    while(!ss.empty()){
        res="/"+ss.top()+res;
        ss.pop();
        
    }
        
    return res;
}




int main(){
    string s="/.../";

   cout<<simplifyPath(s)<<endl;
}