#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

bool cmp1(const string &a, const string &b){
    return (a+b) > (b+a);
}

string largestNumber(vector<int> &num) {
    vector<string> temp;

    for(int i=0; i<num.size(); i++){
        temp.push_back(to_string(num[i]));
    }
    
    sort(temp.begin(),temp.end(),cmp1);
    
    string res="";
    
    for(int i=0; i<temp.size(); i++){
        res+=temp[i];
    }
    
    return res;
        
}


int main(){
    std::vector<int> v;
    v.push_back(3);
    v.push_back(30);
    v.push_back(34);
    v.push_back(5);
    v.push_back(9);
    cout<<largestNumber(v)<<endl;

}