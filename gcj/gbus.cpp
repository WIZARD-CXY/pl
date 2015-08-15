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

int counts[5001];

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<":";
		memset(counts,0,sizeof(counts));
		int n;
		cin>>n;

		for(int j=0; j<n; j++){
			int st,en;
			cin>>st>>en;
			for(int k=st; k<=en; k++){
				counts[k]++;
			}
		}

		int p;
		cin>>p;
		while(p--){
			int city;
			cin>>city;
			cout<<" "<<counts[city];
		}
		cout<<endl;
	}

}