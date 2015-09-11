class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.size();
        int n=version2.size();
        if(m==0 && n==0){
            return 0;
        }else if(m!=0 && n==0){
            return 1;
        }else if(m==0 && n!=0){
            return -1;
        }
        
        int it1 = version1.find('.');
        int it2 = version2.find('.');
        
        string part1;
        
        part1=version1.substr(0,it1);
        
        string part2;
        
        part2=version2.substr(0,it2);
        
        int v1=stoi(part1);
        int v2=stoi(part2);
        
        if(v1<v2){
            return -1;
        }else if(v1>v2){
            return 1;
        }else{
            //continue to compare the part after .
            if(it1==-1 && it2 ==-1){
                return 0;
            }else if(it1 !=-1 && it2==-1){
                if(stoi(version1.substr(it1+1))==0){
                    return 0;
                }
                return 1;
            }else if(it2 !=-1 && it1==-1){
                if(stoi(version2.substr(it2+1))==0){
                    return 0;
                }
                return -1;
            }
            
            return compareVersion(version1.substr(it1+1),version2.substr(it2+1));
        }
    }
};