#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:

    void solve() {
        int n, m, h, r;
        cin >> n >> m >> h >> r;
        vector<int> disks(n, 0);
        for (int i = 0; i < n; i++) cin >> disks[i];
        sort(disks.begin(), disks.end());
        vector<vector<int> > splitedDisks;
        //split into
        for (int i = 0; i < n; i++) {
            if (i == 0 || disks[i] - disks[i-1] > m) {
                vector<int> newgroup;
                newgroup.push_back(disks[i]);
                splitedDisks.push_back(newgroup);
            } else {
                splitedDisks[splitedDisks.size()-1].push_back(disks[i]);
            }
        }
        
        print(splitedDisks);
        
        int ans = 0;
        for (int i = 0; i <=splitedDisks.size(); i++) {
            if (splitedDisks[i][0] <= r) {
                for (int j = 0; j < splitedDisks[i].size(); j++) {
                    if (splitedDisks[i][j] <= r+j) ans++;
                    else break;
                }
                for (int j = 0; j < i; j++) ans += splitedDisks[j].size();
                break;
            }
        }
        ans = min(ans, h);
        printf("%d\n", ans);
    }

    void print(vector<int> &v1) {
        for (int i = 0; i < v1.size(); i++) printf("%d ", v1[i]); printf("\n");
    }

    void print(vector<vector<int> > &v2) {
        for (int i = 0; i < v2.size(); i++) print(v2[i]);
    }
};
void print1(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        printf("%d ",v[i]);
        printf("\n");
    }
}

void print2(vector<vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        print1(v[i]);
    }
}



int main() {
    Solution solution;
    solution.solve();
    return 0;
}