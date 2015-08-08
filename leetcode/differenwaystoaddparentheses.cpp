class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int val=0,i=0;
        for(; i<input.size(); i++){
            if(isdigit(input[i])){
                val=val*10+input[i]-'0';
            }else{
                break;
            }
        }
        
        if(i==input.size()){
            return {val};
        }
        
        // split two parts with every operator
        // divide and conquer
        vector<int> res,leftres,rightres;
        
        for(int k=0; k<input.size(); k++){
            if(!isdigit(input[k])){
                //split using input[i]
                leftres=diffWaysToCompute(input.substr(0,k));
                rightres=diffWaysToCompute(input.substr(k+1));
                
                for(int i=0; i<leftres.size(); i++){
                    for(int j=0; j<rightres.size(); j++){
                        res.push_back(compute(leftres[i],rightres[j],input[k]));
                    }
                }
            }
        }
        
        return res;
        
    }
    
    int compute(int a ,int b , char op){
        switch (op) {
            case '+':
               return a+b;
            case '-':
               return a-b;
            case '*':
               return a*b;
            default:
               return 1;
        }
    }
};