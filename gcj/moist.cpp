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


void print(vector<string> s){
	for(int i=0; i<s.size(); i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);
    
    int t;
	cin>>t;

	for(int cas=1; cas<=t; cas++){
		cout<<"Case #"<<cas<<": ";

		int n;
		cin>>n;
		getchar();
		int cnt=0;

        vector<string> cards;
		for(int i=0; i<n; i++){
			string s;

			getline(cin,s);
			
            cards.push_back(s);
		}
		//print(cards);

		for(int j=1; j<cards.size(); j++){
			//use cards[i] to compare with old one
			string key=cards[j];
			int i=j-1;
            
            if(cards[i]>key){
            	cnt++;
            }
			while(i>=0 && cards[i]>key){
				cards[i+1]=cards[i];
				i--;
			}
			//
			cards[i+1]=key;
		}
		cout<<cnt<<endl;
	}
}