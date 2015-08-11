#include <list>
class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        cap=capacity;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        auto it=cachemap.find(key);
        
        if(it==cachemap.end()){
            return -1;
        }else{
            int val=it->second->second;
            update(it,val);
            
            return val;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        
        auto it=cachemap.find(key);
        
        if(it!=cachemap.end()){
            it->second->second=value;
            update(it,value);
        }else{
            //not exist
            if(cachelist.size()==cap){
                auto back=cachelist.end();
                cachelist.erase(--back);
                cachemap.erase(back->first);
            }
            
            cachelist.push_front(make_pair(key,value));
            cachemap[key]=cachelist.begin();
        }
    }
private:
    list<pair<int, int> > cachelist; // key, value
    // key is key value is the list iterator of the specified key
    unordered_map<int,list<pair<int,int>>::iterator> cachemap;
    
    int cap;
    
    void update(unordered_map<int,list<pair<int,int>>::iterator>::iterator it, int val){
        //move the it to the head of list
        auto l_it=it->second;
        cachelist.erase(l_it);
        cachelist.push_front(make_pair(it->first,val));
        it->second=cachelist.begin();
    }
};
