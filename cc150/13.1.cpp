#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print(string fileName, int k){
	ifstream file (fileName.c_str());
	string buf[k];
    int line=0;

	while(file.good()){
		getline(file,buf[line%k]);
		line++;
	}

	// calculate the circular array start and count

	int start=line>k?(line%k):0;
	int count=min(k,line);

	for(int i=0; i<count; i++){
		cout<<buf[(start+i)%k]<<endl;
	}
	
}

int main(){
	print("1.5.cpp",6);
}