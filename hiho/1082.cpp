#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	freopen("test.in","r",stdin);
	string s;

	while(getline(cin,s)){

		while(true){
			string tmp=s;

			// lowercase all the char
			for(int i=0; i<tmp.size(); i++){
				if(tmp[i]>='A' && tmp[i]<='Z'){
					tmp[i]=tmp[i]-'A'+'a';
				}
			}

			//find the marshtomp
			auto pos=tmp.find("marshtomp");

			if(pos==-1){
				break;
			}
			s.replace(pos,9,"fjxmlhx");
		}
		cout<<s<<endl;
	}
}