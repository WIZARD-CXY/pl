bool cmp(const string &a, const string &b){
        return a+b > b+a;
}
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> temp;
        
        for(auto n: num){
            temp.push_back(to_string(n));
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        string res="";
        if(temp[0]=="0"){
            // if first is 0, just print one zero
            return "0";
        }
        
        for(auto tmp :temp){
            res+=tmp;
        }
        
        return res;
    }
};
