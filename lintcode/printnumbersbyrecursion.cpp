class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if(n==0){
            return res;
        }
        
        string num(n,'0');
        
        helper(res,num,0);
        
        return res;
    }
    
    void helper(vector<int> &res, string &num, int index){
        if(index==num.size()){
            int realnum=stoi(num);
            if(realnum!=0){
                res.push_back(stoi(num));
            }
            return;
        }
        
        for(int i=0; i<10; i++){
            num[index]=i+'0';
            helper(res,num,index+1);
        }
    }
};
