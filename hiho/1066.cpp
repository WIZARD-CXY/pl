#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;

string find(unordered_map<string,string> &father, string x){
	if(x==father[x]){
		return x;
	}else{
		father[x]=find(father,father[x]);
		return father[x];
	}
}


void print(unordered_map<string,string> &mm){
	for(auto it : mm){
		cout<<it.first<<" "<<it.second<<endl;
	}
}

void merge(unordered_map<string, string> &father, string x, string y){
	if(father.find(x)==father.end()){
		father[x]=x;
	}

	if(father.find(y)==father.end()){
		father[y]=y;
	}

	string fx=find(father,x);
	string fy=find(father,y);

	if(fx!=fy){
		father[min(fx,fy)]=max(fx,fy);
	}
	//print(father);
}

int main(){
	freopen("test.in","r",stdin);
	int t;
	cin>>t;
	unordered_map<string,string> father;
	for(int cas=1; cas<=t; cas++){
		int op;
		string name1,name2;

		cin>>op>>name1>>name2;

		if(op==0){
			merge(father,name1,name2);
		}else{
			if(father.find(name1)==father.end()){
				father[name1]=name1;
			}

			if(father.find(name2)==father.end()){
				father[name2]=name2;
			}

			string fx=find(father,name1);
			string fy=find(father,name2);
			//cout<<fx<<" xx "<<fy<<endl;
			if(fx!=fy){
				cout<<"no"<<endl;
			}else{
				cout<<"yes"<<endl;
			}
		}

	}
}