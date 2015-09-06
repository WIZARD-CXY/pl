class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        vector<int> path;
        if(numRows==0){
            return res;
        }
        res.push_back({1});
        if(numRows==1){
            return res;
        }
        for(int i=2;i<=numRows; i++){
            path.clear();
            //push leading 1
            path.push_back(1);
            for(int j=0; j<i-2;j++){
                path.push_back(res[i-2][j]+res[i-2][j+1]);
            }
            path.push_back(1);//push trailing 1
            res.push_back(path);
        }
        return res;
    }
};