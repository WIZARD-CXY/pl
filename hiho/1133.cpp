#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &num){
	for(auto n :num){
		cout<<n<<" ";
	}
	cout<<endl;
}
int partition(vector<int> &num,int l, int r){
	int i=-1;

	for(int j=0; j<r; j++){
		if(num[j]<num[r]){
			swap(num[++i],num[j]);
		}
	}
	swap(num[++i],num[r]);

	return i;
}
int helper(vector<int> &num,int l, int r,int k){
	int p=partition(num,l,r);
    //cout<<p<<endl;
    //print(num);

	if((p-l)+1==k){
		return num[p];
	}else if(p-l+1 > k){
		//find in the left part
		return helper(num,l,p-1,k);
	}else{
		//find in the right part
		return helper(num,p+1,r,k-p+l-1);
	}
}
int main(){
	int n,k;
	cin>>n>>k;

	vector<int> num(n);
	for(int i=0; i<n; i++){
		cin>>num[i];
	}

	if(k>n){
		cout<<-1<<endl;
	}else{
		cout<<helper(num,0,n-1,k)<<endl;
	}
}