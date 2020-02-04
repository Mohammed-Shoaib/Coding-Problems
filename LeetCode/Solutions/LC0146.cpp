/*
Problem Statement: https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
private:
    class Node {
    public:
        int key, val;
        Node(int key, int val) : key(key), val(val) {} 
    };

    int capacity;
    list<Node> cache;
    unordered_map<int, list<Node>::iterator> m;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!m.count(key))
            return -1;
        cache.splice(cache.begin(), cache, m[key]);
        return cache.front().val;
    }
    
    void put(int key, int value) {
        Node node(key, value);
        if (m.count(key))
            cache.erase(m[key]);
        cache.push_front(node);
        m[key] = cache.begin();
        if (m.size() > capacity) {
            m.erase(cache.back().key);
            cache.pop_back();
        }
    }
};