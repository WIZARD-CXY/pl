class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mm[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto it=mm.begin(); it!=mm.end(); it++){
	        auto it2=mm.find(value-(it->first));
	        
	        if(it==it2 && it->second>=2){
	            return true;
	        }else if (it!=it2 && it2!=mm.end()){
	           return true;
	        }
	    }
	    
	    return false;
	}
	unordered_map<int,int> mm;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);