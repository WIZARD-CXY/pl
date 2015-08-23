#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>
#include <unordered_map>
using namespace std;

void gen(vector<string> &res ,string path, int l, int r){
	if(l==0 &&r==0){
		res.push_back(path);
		//cout<<path<<endl;
		return;
	}

	if(l>0){
		gen(res,path+'(',l-1,r);
	}

	if(r>0 && l<r){
		gen(res,path+')',l,r-1);
	}
}
int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";

		int n;
		unsigned long long k;
		cin>>n>>k;

		vector<string> res;
        string path="";

		gen(res,path,n,n);

		if(k>res.size()){
			cout<<"Doesn't Exist!"<<endl;
		}else{
			cout<<res[k-1]<<endl;
		}
	}

}