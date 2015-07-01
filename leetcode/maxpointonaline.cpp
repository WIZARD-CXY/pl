/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()==0){
            return 0;
        }
        unordered_map<double,int> mm;
        int res=1;
        
        for(int i=0; i<points.size(); i++){
            mm.clear();
            int dup=1;
            for(int j=0; j<points.size(); j++){
                if(i==j){
                    //same point 
                    continue;
                }
                if(points[i].x==points[j].x && points[i].y==points[j].y){
                    dup++;
                    continue;
                }
                double k = (points[i].x==points[j].x)?INT_MAX:(points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                
                mm[k]++;
            }
            
            res = max(res,dup);
            unordered_map<double,int>::iterator iter=mm.begin();
            
            for(;iter!=mm.end();iter++){
                if(iter->second+dup>res){
                    res=iter->second+dup;
                }
            }
        }
        
        return res;
        
    }
};