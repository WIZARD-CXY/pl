#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    freopen("test.in","r",stdin);
	int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		int n,m;
		cin>>n>>m;
		
		vector<int> num;
		num.push_back(0);
		for(int i=0; i<n; i++){
			int tmp;
			cin>>tmp;
			num.push_back(tmp);
		}
        // let the cin finish
		if(m>=n){
			cout<<100<<endl;
			continue;
		}

		num.push_back(101);
        int res=0;
		for(int i=1;i<=num.size()-2; i++){
			if(i+m>=num.size()){
				break;
			}
			int len=num[i+m]-num[i-1]-1;
			if(len>res){
				res=len;
			}
		}

		cout<<res<<endl;
	}
}