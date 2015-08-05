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
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int n=points.size();
        
        if(n==0){
            return 0;
        }
        
        unordered_map<double,int> mm;// 'xielv' to point count
        
        int res=1;
        for(int i=0; i<points.size(); i++){
            int dup=1;
            mm.clear();
            for(int j=0; j<points.size(); j++){
                if(i==j){
                    //same point
                    continue;
                }
                
                if(points[i].x==points[j].x && points[i].y==points[j].y){
                    //dup point
                    dup++;
                    continue;
                }
                
                double k=(points[i].x==points[j].x)?INT_MAX:((points[j].y-points[i].y)*1.0/(points[j].x-points[i].x));
                
                mm[k]++;
            }
            // tmpres stores the current point's max 
            int tmpres=dup;
            
            for(auto it=mm.begin(); it!=mm.end(); it++){
                tmpres=max(tmpres,it->second+dup);
            }
            
            res=max(res,tmpres);
        }
        
        return res;
    }
};
