// handle memory leak and alloc fail automatically with 
// smart pointer
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

template<class T>
class SmartPoiner{
private:
	T *ref;
	unsigned int *ref_cnt;

	void remove(){
		--(*ref_cnt);
		if(*(ref_cnt)==0){
			delete ref;
			free(ref_cnt);
			ref=NULL;
			ref_cnt=NULL;
		}
	}
public:
	//construct
	SmartPoiner(T *ptr){
		ref=ptr;
		ref_cnt=(unsigned*)malloc(sizeof(unsigned));
		*ref_cnt=1;
	}

	// cc
	SmartPoiner(SmartPoiner<T> &sptr){
		ref=sptr.ref;
		ref_cnt=sptr.ref_cnt;
		++(*ref_cnt);
		
	}

	SmartPoiner<T>& operator=(SmartPoiner<T> &sptr){
		// if self assign simply return *this
		if(this == &sptr){
			return *this;
		}

		if(*ref_cnt>0){
			//remove the old 
			remove();
		}
		ref=sptr.ref;
		ref_cnt=sptr.ref_cnt;
		++(*ref_cnt);
		
		return *this;
	}
	~SmartPoiner(){
		remove();
	}

	T getValue(){
		return *ref;
	}
	
};

int main(){
	int *a= new int(3);
	SmartPoiner<int> sa(a);
	SmartPoiner<int> sb(a);

	SmartPoiner<int> sc(sa);
	SmartPoiner<int> sd(sa);
	sd=sb;
	cout<<sd.getValue()<<endl;
}