cpclass Solution {
public:
    int countDigitOne(int n) {
        // count digit 1 numbers from right to left
        // ref http://blog.csdn.net/xudli/article/details/46798619
        
        long long res=0;
        //hign means the number above curc
        //lown means the number below curc
        //lowc means the curc factor 
        //30512 if curc==5,highn=30, lown=12, lowc=100
        int highn=n,lowfactor=1,lown=0;
        
        while(highn>0){
            int curc=highn%10;
            highn=highn/10;
            
            if(curc==1){
                //305*100+2+1
                res+=highn*lowfactor+lown+1;
            }else if(curc==0){
                //curc=0 3*10000
                res+=highn*lowfactor;
            }else{
                // curc=5>1
                // 305x1000
                res+=(highn+1)*lowfactor;
            }
            //update lowfactor and lown
            lown=curc*lowfactor+lown;
            lowfactor*=10;
            
        }
        return res;
        
    }
};