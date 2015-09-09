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
        int n=points.size();
        int res=0;
        
        for(int i=0; i<n; i++){
            unordered_map<double,int> mm; // key is ratio, value is number
            int dup=1;

            for(int j=0; j<n; j++){
                if(j==i){
                    //same point
                    continue;
                }
                
                if(points[i].x==points[j].x && points[i].y==points[j].y){
                    dup++;
                }else if(points[i].x==points[j].x){
                    // INT_MAX ratio vertical
                    mm[INT_MAX]++;
                }else{
                    double ratio=(points[j].y-points[i].y)*1.0/(points[j].x-points[i].x);
                    mm[ratio]++;
                }
                
            }
            
            // find the max point line ratio
            int maxpoints=0;
            for(auto r : mm){
                maxpoints=max(maxpoints,r.second);
            }
            
            res=max(res,maxpoints+dup);
        }
        
        return res;
    }
};