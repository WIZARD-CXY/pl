struct node{
    int index;
    int val;
};

bool cmp(node &a, node &b){
    return a.val<b.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector<node> temp;
        int i=0;
        int j=numbers.size()-1;
        
        for(int i=0; i<numbers.size(); i++){
            node t;
            t.index=i;
            t.val=numbers[i];
            temp.push_back(t);
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        while(i<j){
            int sum = temp[i].val+temp[j].val;
            
            if(sum==target){
                if(temp[i].index<temp[j].index){
                    res.push_back(temp[i].index+1);
                    res.push_back(temp[j].index+1);
                    
                }else{
                     res.push_back(temp[j].index+1);
                     res.push_back(temp[i].index+1);
                }
                return res;
            }else if(sum<target){
                i++;
            }else{
                j--;
            }
        }
        return res;
        
    }
};