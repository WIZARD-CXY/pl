#include <iostream>
using namespace std;

string printBinary(double number){
	string res=".";
    
    while(number>0){
    	double r=number*2;

    	if(r>=1){
    		res+="1";
    		number=r-1;
    	}else{
    		res+="0";
    		number=r;
    	}

    	if(res.size()>33){
		    return "ERROR";
	    }
	    //cout<<number<<endl;
    }
	
    return res;

}
int main(){
    cout<<printBinary(0.75+0.125+1.0/32)<<endl;
}