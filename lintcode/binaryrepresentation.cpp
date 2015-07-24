class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        int dotidx=n.find('.');
        
        int intege=0;
        double frac=0.0;
        
        if(dotidx!=-1){
            intege=stoi(n.substr(0,dotidx));
            // including leading dot.
            frac=strtod(n.substr(dotidx).c_str(),NULL);
        }else{
            intege=stoi(n);
        }
        
        // convert the integer to binary represent;
        string intbuf="";
        if(intege==0){
            intbuf="0";
        }
        while(intege!=0){
            intbuf=(char)((intege%2)+'0')+intbuf;
            intege/=2;
        }
        
        //convert the fraction to binary representation
        string fracbuf="";
        while(frac>0.0){
            if(fracbuf.size()>32){
                return "ERROR";
            }
            frac*=2;
            if(frac>=1.0){
                fracbuf+="1";
                frac-=1.0;
            }else{
                fracbuf+="0";
            }
        }
        
        return fracbuf==""?intbuf:intbuf+"."+fracbuf;
    }
};

