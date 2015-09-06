class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0){
            return res;
        }
        
        vector<int> pre={1};
        
        if(rowIndex==0){
            return pre;
        }
        
        for(int i=1;i<=rowIndex; i++){
            res.clear();
            res.push_back(1);
            for(int j=0; j<i-1;j++){
                res.push_back(pre[j]+pre[j+1]);
            }
            res.push_back(1);
            pre=res;
        }
        
        return res;
    }
};