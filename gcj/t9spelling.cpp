#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
    // first parameter is testfile name
	freopen(argv[1],"r",stdin);

	int n;
	cin>>n;
	getchar();
	vector<string> mm={"2","22","222","3","33","333","4",
	                 "44","444","5","55","555","6","66",
	                 "666","7","77","777","7777","8","88",
	                 "888","9","99","999","9999"};

	for(int i=1; i<=n; i++){
		string s;
		getline(cin,s);

        string res;

        if(s.size()==1){
        	cout<<"Case #"<<i<<": "<<mm[s[0]-'a']<<endl;
        }

        string pre=mm[s[0]-'a'];
        cout<<"Case #"<<i<<": "<<pre;
        for(int j=1; j<s.size(); j++){
        	if(s[j]==' '){
        		res+="0";
        	}

        	if(pre[0]!=(mm[s[j]-'a'][0])){
        		res+=mm[s[j]-'a'];
        	}else{
        		res+=(" "+mm[s[j]-'a']);
        	}
        	pre=mm[s[j]-'a'];

        }
		cout<<res<<endl;
	}

}