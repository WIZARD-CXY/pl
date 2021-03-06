//check duplicates
void checkdups(int array[]){
	bitset bs = new bitset(32000);

	for(int i=0; i<array.size(), i++){
		int num=array[i];
		int idx=num-1;

		if(bs.get(idx){
			//already exist
			cout<<num;
		}else{
			bs.set(idx);
		}
	}
}

struct BitSet{
	int bitset[];

	Bitset(int size){
		bitset=new int[size>>5]; // divide 32, one int have 32 bits
	}

	bool get(int idx){
		int wordnumber=(idx>>5); // /32
		int bitnumber=(idx&0x1f); //%32
		return (bitset[wordnumber] & (1<<bitnumber))!=0;
	}

	void set(int pos){
		int wordnumber=(pos>>5);
		int bitnumber=(pos&0x1f);

		bitset[wordnumber]|= (1<<bitnumber);
	}
}