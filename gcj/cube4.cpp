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
#include <climits>
using namespace std;

// x[i] records number i's x loc
// y[i] records number j's y loc
int x[1000001];
int y[1000001];

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int i=1; i<=t; i++){
		cout<<"Case #"<<i<<": ";

		int s;
		cin>>s;

		for(int i=0; i<s; i++){
			for(int j=0; j<s; j++){
				int num;
				cin>>num;
				x[num]=i;
				y[num]=j;
				
			}
		}

		int res=1;
		int start=1;

		for(int i=1; i<=s*s; i++){
			int j=i+1;

			while(j<=s*s && (abs(x[j]-x[j-1])+abs(y[j]-y[j-1]))==1){
				j++;
			}

			if(j-i>res){
				res=j-i;
				start=i;
			}
			i=j-1;
		}

		cout<<start<<" "<<res<<endl;
	}

}