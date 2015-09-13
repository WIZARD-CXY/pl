#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin>>n;
	getchar();
	unordered_map<string,int> m2e;
	unordered_map<int,string> e2m;

	m2e["tret"]=0;m2e["jan"]=1;m2e["feb"]=2;m2e["mar"]=3;m2e["apr"]=4;
	m2e["may"]=5;m2e["jun"]=6;m2e["jly"]=7;m2e["aug"]=8;
	m2e["sep"]=9;m2e["oct"]=10;m2e["nov"]=11;m2e["dec"]=12;
	m2e["tam"]=1*13;m2e["hel"]=2*13;m2e["maa"]=3*13;m2e["huh"]=4*13;
	m2e["tou"]=5*13;m2e["kes"]=6*13;m2e["hei"]=7*13;m2e["elo"]=8*13;
	m2e["syy"]=9*13;m2e["lok"]=10*13;m2e["mer"]=11*13;m2e["jou"]=12*13;
	
	e2m[0]="tret";e2m[1]="jan";e2m[2]="feb";e2m[3]="mar";e2m[4]="apr";
	e2m[5]="may";e2m[6]="jun";e2m[7]="jly";e2m[8]="aug";
	e2m[9]="sep";e2m[10]="oct";e2m[11]="nov";e2m[12]="dec";
	e2m[13]="tam";e2m[2*13]="hel";e2m[3*13]="maa";e2m[4*13]="huh";
	e2m[5*13]="tou";e2m[6*13]="kes";e2m[7*13]="hei";e2m[8*13]="elo";
	e2m[9*13]="syy";e2m[10*13]="lok";e2m[11*13]="mer";e2m[12*13]="jou";
    
	for(int i=0; i<n; i++){
		string tmp;
		getline(cin,tmp);
        
        // trim leading and trailing " "
        int start=0;
        while(start<tmp.size() & tmp[start]==' '){
        	start++;
        }

        int end=tmp.size()-1;

        while(end>=0 && tmp[end]==' '){
        	end--;
        }

        tmp=tmp.substr(start,end-start+1);
		
		if(tmp[0]>='0' && tmp[0] <='9'){
			//earth to mars
			int num=stoi(tmp);
           
			string res="";
			if(num==0){
				cout<<"tret"<<endl;
				continue;
			}
			bool first=true;
			while(num){
				if(first){
					res=e2m[(num%13)];
					first=false;
					if(res=="tret" && num/13!=0){
						res="";
					}
				}else{
					if(res.empty()){
						res=e2m[(num%13)*13];
					}else{
						res=e2m[(num%13)*13]+" "+res;
					}
				}
				num/=13;
			}
			cout<<res<<endl;
		}else{
			//mars to earth
			int spacepos=tmp.find(" ");
			if(spacepos==-1){
				// only one digit
				//cout<<"haha "<<tmp<<"#"<<endl;
				cout<<m2e[tmp]<<endl;
			}else{
				int newstart=spacepos;
                while(newstart<tmp.size() && tmp[newstart]==' '){
                	newstart++;
                }
				cout<<m2e[tmp.substr(0,spacepos)]+m2e[tmp.substr(newstart)]<<endl;
			}
		}
	}
}