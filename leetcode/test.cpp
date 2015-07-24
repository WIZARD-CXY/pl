#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        string res="";
        int dotidx=n.find('.');
        
        string integer="";
        string fraction="";
        int intege=0;
        double frac=0.0;
        
        if(dotidx!=-1){
            integer=n.substr(0,dotidx);
            intege=stoi(integer);
            // including leading dot.
            fraction=n.substr(dotidx); 
            frac=strtod(fraction.c_str(),NULL);
        }else{
            integer=n;
            intege=stoi(integer);
        }
        
        // convert the integer to binary represent;
        string intbuf="";
        if(intege==0){
            intbuf="0";
        }
        while(intege!=0){
            intbuf=(char)((intege%2)+'0')+intbuf;
            intege/=2;
        }
        
        //convert the fraction
        string fracbuf="";
        while(frac>0.0){
            if(fracbuf.size()>32){
                return "ERROR";
            }
            frac*=2;
            if(frac>=1.0){
                fracbuf+="1";
                frac-=1.0;
            }else{
                fracbuf+="0";
            }
        }
        
        return fracbuf==""?intbuf:intbuf+"."+fracbuf;
    }
};




int main(){
    Solution sln;
    cout<<sln.binaryRepresentation("3.72");
}

