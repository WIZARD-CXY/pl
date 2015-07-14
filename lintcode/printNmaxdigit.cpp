#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    void printnmaxDigit(int n){
        string number(n,'0');

        PrintRecursively(number,n,0);
    }

    void PrintRecursively(string& num,int n, int index){
        if(index==n){
            print(num);
            return;
        }

        for(int i=0; i<=9; i++){
            num[index]=i+'0';
            PrintRecursively(num,n,index+1);
        }

    }

    void print(string &num){
        int i=0;

        while(i<num.size() && num[i]=='0'){
            i++;
        }
        while(i<num.size()){
            cout<<num[i++];
        }
        cout<<endl;
    }
};

int main(){
    Solution sln;

    sln.printnmaxDigit(3);
}