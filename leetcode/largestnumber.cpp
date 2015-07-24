bool cmp(const string &s1, const string &s2) {
        return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> temp;
    
        for (int i = 0; i < num.size(); ++i) {
            temp.push_back(to_string(num[i]));
        }
        sort(temp.begin(), temp.end(), cmp);
        string res="";
        
        //when the first element is "0".
        //the input num must be [0,0,0...]
        //so just return "0"
        if(temp[0]=="0"){
            return "0";
        }

        int i=0; 
        
        while(i<temp.size()){
            res+=temp[i];
            i++;
        }
        return res;
    }
};