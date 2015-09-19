class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        b[0]=v1.begin();
        e[0]=v1.end();
        b[1]=v2.begin();
        e[1]=v2.end();
    }

    int next() {
        if(b[0]==e[0]){
            return *(b[1]++);
        }else if(b[1]==e[1]){
            return *(b[0]++);
        }else{
            int val=*(b[p]++);
            p=(p+1)%2;
            return val;
        }
    }

    bool hasNext() {
        return b[0]!=e[0] || b[1]!=e[1];
    }
    vector<int>::iterator b[2],e[2];
    int p=0;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */