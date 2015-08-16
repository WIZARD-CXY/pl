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

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;
	double pi=acos(-1.0);
	double g=9.8;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";
        
        int v,d;
		cin>>v>>d;

		double t=min(g*d/(v*v),1.0);

		double theta=asin(t)/2;

        cout<<fixed<<setprecision(7) << theta*180/pi << endl;
	}

}