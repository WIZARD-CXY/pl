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
        
        auto it = cachemap.find(key);
        
        if(it==cachemap.end()){
            return -1;
        }else{
            int val=it->second->val;
            // move it to the first of the list
            updateList(it,key,val);
            return val;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        // find if the given kv pair is in the list
        auto it=cachemap.find(key);
        if(it!=cachemap.end()){
            // kv is in the map, update
            it->second->val=value;
            updateList(it,key,value);
        }else{
            // new kv 
            if(cap==cachelist.size()){
                // reach the capacity
                auto last=cachelist.end();
                cachelist.erase(--last);
                cachemap.erase(last->key);
            }
            cachelist.push_front(CacheNode(key,value));
            cachemap[key]=cachelist.begin();
        }
    }
private:
    struct CacheNode{
        int key;
        int val;
        CacheNode(int k, int v){
            key=k;
            val=v;
        }
    };
    
    void updateList(unordered_map<int,list<CacheNode>::iterator>::iterator it, int key, int val){
        // move the it to the head of list
        cachelist.erase(it->second);
        cachelist.push_front(CacheNode(key,val));
        //update the cachemap 
        cachemap[key]=cachelist.begin();
    }
    
    // cachelist stores the val
    list<CacheNode> cachelist;
    
    // the map key is cache key, value is the list iterator that 
    // points to the val
    unordered_map<int,list<CacheNode>::iterator> cachemap;
    
    int cap;
};