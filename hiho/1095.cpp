#include <iostream>
#include <vector>
using namespace std;

bool isOK(int mid, vector<int> &num, int n){
	int hi=0;
	int ho=0;
    int cap=0;
	for(int i=0; i<n; i++){
		cap+=mid;

		if(cap<=num[i]){
			hi++;
			cap=0;
		}else{
			ho++;
			cap-=num[i];
		}
	}

	return ho>hi;
}
int main(){
	int n,k;
	cin>>n>>k;

	vector<int> num(n);

	for(int i=0; i<n; i++){
		cin>>num[i];
	}

	int l=1;
	int r=k+1;

	while(l<r){
		int mid = l+((r-l)>>1);

		if(isOK(mid,num,n)){
			r=mid;
		}else{
			l=mid+1;
		}
	}

	cout<<l<<endl;
}