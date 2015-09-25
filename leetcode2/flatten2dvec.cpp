class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i=vec2d.begin();
        end=vec2d.end();
    }

    int next() {
        return (*i)[j++];
    }

    bool hasNext() {
        while(i!=end && j==(*i).size()){
            //reach the end of vector, move to the next vector
            i++;
            j=0;
        }
        
        return i!=end;
    }
    vector<vector<int> >::iterator i,end;
    int j=0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */