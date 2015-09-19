class ZigzagIterator {
public:
    //kind like bfs
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()!=0){
            qq.push(make_pair(v1.begin(),v1.end()));
        }
        
        if(v2.size()!=0){
            qq.push(make_pair(v2.begin(),v2.end()));
        }
    }

    int next() {
        auto it = qq.front().first;
        auto endit = qq.front().second;
        qq.pop();
        if(it+1!=endit){
           qq.push(make_pair(it+1,endit)); 
        }
        
        return *it;
    }

    bool hasNext() {
        return !qq.empty();
    }
    queue<pair<vector<int>::iterator,vector<int>::iterator> > qq; 
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */