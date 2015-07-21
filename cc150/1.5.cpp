#include <iostream>
#include <string>
using namespace std;

string compress(string &a){
	string res;

	if(a.size()==0){
		return res;
	}

	char pre=a[0];
	int count=1;
	for(int i=1; i<a.size(); i++){
		if(a[i]==pre){
			count++;
		}else{
			res+=(pre+to_string(count));
			count=1;
			pre=a[i];
		}

	}
	res+=(pre+to_string(count));
	return res;
}
int main(){
	string test="aabcccccaaa";
	cout<<compress(test)<<endl;
}