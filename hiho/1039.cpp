#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int process(string s){
	int count=s.size();

	while(true){
		//continue to merge unless it is not mergable
		//s reduced to tmp

		string tmp="";
	    cout<<"--"<<s<<endl;

		int i=0,j=1;
		for(; j<s.size(); j++){
			if(s[i]!=s[j]){
				tmp+=s[i];
			}else{
				//reduce it
				while(j<s.size() && s[i]==s[j]){
					j++;
				}
			}
			//a new start
			i=j;
		}
		if(j==s.size()){
			tmp+=s[j-1];
		}
		if(tmp.size()==s.size()){
			//can't reduce anymore return
			count=tmp.size();
			return count;
		}
		
		s=tmp;
	}
	return count;
}
int main(){
	freopen("test.in","r",stdin);
	int t;

	cin>>t;

	for(int cas=1; cas<=t; cas++){
		string s;
		cin>>s;
		int res=INT_MIN;

		for(int i=0;i<s.size(); i++){
			for(char c='A'; c<='C'; c++){
				//try to insert every pos with A,B,C
				string tmp=s;
				tmp.insert(i,1,c);
				// after merge the same one the last length
				cout<<"--------------"<<endl;
				int len=process(tmp);
				cout<<"--------------"<<endl;
				res=max(res,int(s.size())+1-len);
			}
		}
		cout<<res<<endl;
	}
}