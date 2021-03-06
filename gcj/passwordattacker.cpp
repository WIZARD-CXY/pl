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

const int maxn=105;
const int mod=1000000007;

long long fact[maxn];
long long s[maxn][maxn];

void preProcess(){
	fact[1]=1;
	for(int i=2; i<=maxn; i++){
		fact[i]=fact[i-1]*i%mod;
	}

	//generare stirling

	s[1][1]=1;

	for(int i=2; i<maxn; i++){
		s[i][1]=s[i][i]=1;
		for(int j=2; j<i; j++){
			s[i][j]=(s[i-1][j-1]+(long long)j*s[i-1][j])%mod;
		}
	}
}

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;
	preProcess();

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";
		int n,m;
		cin>>m>>n;
		
		long long res=fact[m]*s[n][m]%mod;
		cout<<res<<endl;
	}

}