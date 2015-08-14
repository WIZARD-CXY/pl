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
	string temp;
	getline(cin,temp);

	vector<string> mm={"2","22","222","3","33","333","4",
	                 "44","444","5","55","555","6","66",
	                 "666","7","77","777","7777","8","88",
	                 "888","9","99","999","9999"};

	for(int i=1; i<=n; i++){
		string s;
		getline(cin,s);
		cout<<s.size()<<endl;

  //       string res;

  //       if(s.size()==1){
  //       	cout<<"Case #"<<i<<": ";
  //       	if(s[0]!=' '){
  //       		cout<<mm[s[0]-'a']<<endl;;
  //       	}else{
  //       		cout<<"0"<<endl;
  //       	}
  //       	continue;
  //       }

  //       cout<<"Case #"<<i<<": ";
  //       string pre;
  //       if(s[0]!=' '){
  //       	pre=mm[s[0]-'a'];
  //       	cout<<pre;
  //       }else{
  //       	pre=" ";
  //       	cout<<"0";
  //       }
        
  //       for(int j=1; j<s.size(); j++){
  //       	if(s[j]==' ' && s[j-1]!=' '){
  //       		res+="0";
  //       		continue;
  //       	}else if (s[j]==' ' && s[j-1]==' '){
  //       		res+=" 0";
  //       		continue;
  //       	}
            
  //           //s[j]!=' '
  //       	if(pre[0]!=(mm[s[j]-'a'][0])){
  //       		res+=mm[s[j]-'a'];
  //       	}else{
  //       		res+=(" "+mm[s[j]-'a']);
  //       	}
  //       	pre=mm[s[j]-'a'];

  //       }
		// cout<<res<<endl;
	}

}