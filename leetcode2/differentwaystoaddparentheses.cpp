class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int i=0;
        vector<int> res;
        int val=0;
        
        for(;i<input.size(); i++){
            if(isdigit(input[i])){
                val=val*10+input[i]-'0';
            }else{
                break;
            }
        }
        
        if(i==input.size()){
            //base case if input contains only digit just return it
            return {val};
        }
        
        //split across a operator
        
        for(int k=0; k<input.size(); k++){
            if(!isdigit(input[k])){
                //input[k] is operator
                // split across it
                
                vector<int> lres=diffWaysToCompute(input.substr(0,k));
                vector<int> rres=diffWaysToCompute(input.substr(k+1));
                
                for(int j=0; j<lres.size(); j++){
                    for(int l=0; l<rres.size(); l++){
                        res.push_back(compute(lres[j],rres[l],input[k]));
                    }
                }
            }
        }
        
        return res;
    }
    int compute(int a, int b, char op){
        switch (op){
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