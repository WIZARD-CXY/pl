#include<iostream>
using namespace std;

string countAndSay(int n) {
    string res,temp;
    if(n==0){
        return res;
    }
    char curC;
    res="1";
    int count;
    
    for(int i=1; i<n; i++){
        temp=res;
        res="";
        curC=temp[0];
        count=1;
        
        for(int j=1; j<temp.size(); j++){
            if(curC == temp[j]){
                count++;
            } else{
                res.push_back(('0'+count));
                res.push_back(curC);
                curC=temp[j];
                count=1;
            }
        }
        res.push_back(count+'0');
        res.push_back(curC);
    }
    
    return res;
}

int main(){
	cout<<countAndSay(5)<<endl;
}
