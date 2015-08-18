long long numberofInts = ((long)Integer.MAX_VALUE)+1;

byte[] bitfield = new byte [int(numberofInts/8)];

void findOpennumber(){
	file=new file("filename")

	while(file.hasNextInt()){
	int n=file.next();
	bitfield[n/8]|=1<<(n%8);
	}

	for(int i=0; i<bitfield.size(); i++){
	    for(int j=0; j<8; j++){
	       if((bitfield[i] &(1<<j))==0){
	           //missing element
	           cout<<i*8+j<<endl;
	       }
	    }
	}
} 


// advanced with not enough memory like index sort
//count the number of range

int bitsize=1048576 //range,  2^20 bit every block covers 1048576 integer
int blocknum=4096 // 2^12 block

byte[] bitfield = new byte[bitsize/8];
int[] blocks=new int[blocknum];

void findOpenNumber() {
	int starting =-1;
	in =file("file.txt");

	while(file.hasnext()){
	   in = file.next();
	   blocks[n/(bitsize)]++; //count++
	}

	for(int i=0; i<blocks.size(); i++){
	     if(block[i]<bitfiled.len*8){
	         //if count < 2^20
	         starting = i*bitfield*8;
	         break;
	     }
	}

	// scan the file again
    
	while(in.hasNext()){
	      int n=in.nextInt();
	      // if n is in range [starting , starting + bitfield.size()*8)
          
	      if(n>=starting && n<starting + bitfield.size()*8){
	         bitfield[(n-starting)/8] |= 1<<((n-starting)%8);
	      }
	}

	for(int i=0; i<bitfield.size(); i++){
	    for(int j=0; j<8; j++){
	        if((bitfield[i] & (1<<j))==0){
	           //find it
	           cout<<i*8+j+starting<<endl;
	           return;
	        }
	    }
	}
}