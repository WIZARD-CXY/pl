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
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        string temp=A;
        
        while(k--){
            //delete the first decreasing element
            int i=0;
            while(i<temp.size()-1 && temp[i]<=temp[i+1]){
                i++;
            }
            temp.erase(i,1);
        }
        
        return temp;
    }
};

int main(){
    Solution sln;
    cout<<sln.DeleteDigits("178542",4);
}

