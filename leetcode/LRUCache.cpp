class LRUCache{
private:
   struct CacheNode{
       int key;
       int value;
       CacheNode(int k, int v):key(k),value(v){}
   };
    
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()) return -1;
        
        // set the k v in the front ,and update the map's node location
        cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
        cacheMap[key]=cacheList.begin();
        return cacheMap[key]->value;
        
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key)==cacheMap.end()){
            //new kv
            if(cacheList.size()==capacity){
                //the list is full delete the tail of the list
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //move it to the front
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key]=cacheList.begin();
        }else{
            //old kv 
            cacheMap[key]->value=value;
            //move it to the front
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key]=cacheList.begin();
        }
        
    }
private:
    list<CacheNode> cacheList;
    unordered_map<int,list<CacheNode>::iterator> cacheMap;
    int capacity;
};