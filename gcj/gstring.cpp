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
#define MAX 100010

long long len[MAX];
unordered_map<long long, int> mm;

int func(long long x){
	if(mm[x] == 1){
        return 0;
	}
    for(int i = 0; i < 70; i++) {
        if (x > len[i] && x <= len[i + 1]) {
            long long y = len[i + 1] - x + 1;
            return 1 - func(y);
        }
    }
    return 0;
}
int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";

		long long k;
		cin>>k;

		for(int i=1; i<70; i++){
			len[i]=len[i-1]*2+1;
			mm[len[i]+1]=1;
		}

		mm[1]=1;
		cout<<func(k)<<endl;
	}

}