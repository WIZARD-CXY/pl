/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        
        helper(nuts,bolts,compare,0,nuts.size()-1);
    }
    
    int swap(string &a, string &b){
        string c=a;
        a=b;
        b=c;
    }
    
    void helper(vector<string> &nuts, vector<string> &bolts, Comparator &compare, int l, int r){
        if(l<r){
            //use bolts[l] as pivot to partition nuts
            string pivot=bolts[l];
            int idx=sortnuts(nuts,pivot,l,r,compare);
            //use nuts[idx] to partition bolts
            sortbolts(bolts,nuts[idx],l,r,compare);
            
            // recursively call 
            helper(nuts,bolts,compare,l,idx-1);
            helper(nuts,bolts,compare,idx+1,r);
        }
    }
      
    int sortnuts(vector<string> &nuts, string pivot, int l, int r, Comparator &compare){
        int i=l-1;
        for(int j=l; j<=r; j++){
            if(compare.cmp(pivot,nuts[j])==0){
                swap(nuts[j],nuts[r]);
                break;
            }
        }
        
        for(int j=l; j<r; j++){
            if(compare.cmp(nuts[j],pivot)==-1){
                //nuts[j] < pivot
                swap(nuts[++i],nuts[j]);
            }
        }
        swap(nuts[++i],nuts[r]);
        return i;
    }
    
    int sortbolts(vector<string> &bolts, string pivot, int l, int r, Comparator &compare){
        int i=l-1;
        
        for(int j=l; j<=r; j++){
            if(compare.cmp(pivot,bolts[j])==0){
                swap(bolts[j],bolts[r]);
                break;
            }
        }
        
        for(int j=l; j<r; j++){
            if(compare.cmp(bolts[j],pivot)==-1){
                //bolts[j] < pivot
                swap(bolts[++i],bolts[j]);
            }
        }
        swap(bolts[++i],bolts[r]);
        return i;
    }
};
