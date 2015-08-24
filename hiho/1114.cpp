#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	cin>>t;

	int m;
	cin>>m;

	vector<int> mine(m);
	for(int i=0; i<m; i++){
		cin>>mine[i];
	}

	vector<int> mark(m);

	//assume first has mine
	mark[0]=1;
    bool flag=1;

	for(int i=1; i<m; i++){
		if(i==1){
			mark[i]=mine[0]-mark[0];
		}else{
			mark[i]=mine[i-1]-mark[i-1]-mark[i-2];
		}

		if(mark[i]!=0 || mark[i]!=1){
			flag=0;
			break;
		}
	}

	if(!flag){
		// the first has no mine
	}
}