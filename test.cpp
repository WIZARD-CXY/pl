#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    if(triangle.size()==0){
        return 0;
    }
    
    int layer=triangle.size();
    int largestSize=triangle[triangle.size()-1].size();
    
    int d[layer][largestSize];
    for(int i=0; i<largestSize; i++){
        d[layer-1][i]=triangle[layer-1][i];
    }
    
    for(int i=layer-2; i>=0;i++){
        for(int j=0; j<triangle[i].size(); j++){
            d[i][j]=min(d[i+1][j],d[i+1][j+1])+triangle[i][j];
        }
    }
    
    return d[0][0];
}


int main(){
    vector<vector<int> > triangle;
    vector<int> temp;

    temp.push_back(1);
    triangle.push_back(temp);

    temp.clear();
    temp.push_back(2);
    temp.push_back(3);

    triangle.push_back(temp);
    cout<<minimumTotal(triangle)<<endl;

}
