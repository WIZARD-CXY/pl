#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverse(string &s, int start ,int end){
	while(start<end){
		swap(s[start++],s[end--]);
	}

}
int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);

	int n;
	cin>>n;
	getchar();

	for(int i=1; i<=n; i++){
		string s;
		getline(cin,s);
		reverse(s,0,s.size()-1);

        int start=0;
        int end=0;
		while(end<s.size()){
			if(s[end]!=' '){
				end++;
				continue;
			}
			// end is ' '
			reverse(s,start,end-1);
			end++;
			start=end;
		}

		reverse(s,start,end-1);
		cout<<"Case #"<<i<<": "<<s<<endl;
	}

}