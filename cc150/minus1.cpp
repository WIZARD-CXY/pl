#include<iostream>
#include<string>

using namespace std;

string minusone(string s){
	string res="";

	//assume s is larger or equal to 1
	int borrow=1;

	for(int i=s.size()-1; i>=0; i--){
		int tmpres=s[i]-'0'-borrow;
		if(tmpres>=0){
			borrow=0;
			res=char(tmpres+'0')+res;
		}else{
			borrow=1;
			res=char(tmpres+10+'0')+res;
		}
	}

    int i=0;
	while(i<res.size()-1 && res[i]=='0'){
		i++;
	}


	return res.substr(i);
}

string addone(string &s){
	int sign=1;

	if(s[0]=='-'){
		sign=-1;
	}

	return '-'+minusone(s.substr(1));


}
int main(){
    string s="-101000001010101010999101001010";
	cout<<addone(s)<<endl;
}