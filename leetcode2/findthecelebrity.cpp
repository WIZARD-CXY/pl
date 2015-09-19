// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int can=0;
        
        for(int i=1; i<n; i++){
            if(knows(can,i)){
                //if candidates knows i ,then candidates is not can any more,
                // i maybe can
                can=i;
            }
        }
        
        //check
        for(int i=0; i<n; i++){
            if(can==i){
                continue;
            }
            if(knows(can,i) || !knows(i,can)){
                //if i don't know the candidate or candidates know i, he is not celebrity
                return -1;
            }
        }
        
        return can;
    }
};