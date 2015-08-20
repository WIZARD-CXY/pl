#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<string> rotate(vector<string> &s){
	//rotate string 90 degree;
	vector<string> ret(3,string(3,'0'));

	for(int i=0; i<3; i++){
		ret[i][2]=s[0][i];
	}
	for(int i=0; i<3; i++){
		ret[i][1]=s[1][i];
	}
	for(int i=0; i<3; i++){
		ret[i][0]=s[2][i];
	}

	return ret;

}

bool match(vector<string> &svec, int x, int y, vector<string> sur){
	if(svec[x-1][y-1]!=sur[0][0] || svec[x-1][y]!=sur[0][1] || svec[x-1][y+1]!=sur[0][2] ||
	   svec[x][y-1]!=sur[1][0] || svec[x][y]!=sur[1][1] || svec[x][y+1]!=sur[1][2] ||
	   svec[x+1][y-1]!=sur[2][0] || svec[x+1][y]!=sur[2][1] || svec[x+1][y+1]!=sur[2][2]){
		return false;
	}

	return true;
}
int main(){
    freopen("test.in","r",stdin);
	int n,m;
	cin>>n>>m;

	vector<string> svec;

	for(int i=0; i<n; i++){
		string tmp;
		cin>>tmp;
		svec.push_back(tmp);
	}

	vector<string> surr;
	for(int i=0; i<3; i++){
		string tmp;
		cin>>tmp;
		surr.push_back(tmp);
	}

	vector<string> surr1=rotate(surr);
	vector<string> surr2=rotate(surr1);
	vector<string> surr3=rotate(surr2);

	char center=surr[1][1];

	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			if(svec[i][j]==center){
				if(match(svec,i,j,surr) || match(svec,i,j,surr1) 
				   || match(svec,i,j,surr2) || match(svec,i,j,surr3)){
					cout<<i+1<<" "<<j+1<<endl;
				}
			}
		}
	}
}