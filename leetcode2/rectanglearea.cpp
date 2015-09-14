class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaa=(C-A)*(D-B);
        int areab=(G-E)*(H-F);
        
        int leftx=max(A,E);
        int lefty=max(B,F);
        int rightx=min(C,G);
        int righty=min(D,H);
        
        if(rightx<leftx|| righty<lefty){
            //two rectangle don't intersect
            return areaa+areab;
        }
        int areacommon=(rightx-leftx)*(righty-lefty);
        
        return areaa+areab-areacommon;
    }
};