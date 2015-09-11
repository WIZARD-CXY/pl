#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	vector<int> num(n);

	for(int i=0; i<n; i++){
		cin>>num[i];
	}

	int i=-1;
	bool found=false;

	for(int j=0; j<n; j++){
		if(num[j]<k){
			swap(num[++i],num[j]);
		}
		if(num[j]==k){
			found=true;
		}
	}

	if(!found){
		cout<<-1<<endl;
	}else{
		cout<<i+2<<endl;
	}

}