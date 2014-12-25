#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int stoi(string s){
    stringstream ss;
    ss<<s;
    int num;
    ss>>num;
    return num;
}
void split2vector(string version,vector<int> &res){
    
    size_t pos;
    
    while((pos = version.find("."))!=string::npos){
        string first = version.substr(0,pos);
        
        res.push_back(stoi(first));
        
        version=version.substr(pos+1);
    }
    res.push_back(stoi(version));
    
}
int compareVersion(string version1, string version2) {
    vector<int> v1;
    vector<int> v2;
    
    split2vector(version1,v1);
    split2vector(version2,v2);
    int size1 = v1.size();
    int size2 = v2.size();
    int minsize=min(size1,size2);
    
    int i;
    for(i=0; i<minsize; ){
        if(v1[i]==v2[i]){
            i++;
        }else if(v1[i]>v2[i]){
            return 1;
        }else{
            return -1;
        }
    }
    
    if(i==size1){
        //version2 string is longer if it is not all zero it should be bigger
        int j=size2-1;
        while(j>=i){
            if(v2[j--]!=0){
                return -1;
            }
        }
        return 0;
    }
    if(i==size2){
        //version1 string is longer if it is not all zero it should be bigger
        int j=size1-1;
        while(j>=i){
            if(v1[j--]!=0){
                return 1;
            }
        }
        return 0;
    }
    
}


int main(){
    cout<<compareVersion("1","1.1")<<endl;

}