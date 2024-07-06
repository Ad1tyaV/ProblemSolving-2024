#include<iostream>
#include<unordered_map>

using namespace std;

struct DLL{
    int key;
    int value;
    DLL* previous;
    DLL* next;

    DLL(int key, int value): key(key), value(value), previous(nullptr), next(nullptr) {}
    DLL(int key, int value, DLL* prev, DLL* next): key(key), value(value), previous(prev), next(next) {}    
};

class LRUCache {
    private:
    int capacity;
    unordered_map<int, DLL*> cache;
    DLL* head;
    DLL* tail;

    public:      
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->previous = head;
    }

    void adjust(DLL* data) {
        if(tail->previous==data)
            return;

        DLL* previous = data->previous;                       
        DLL* next = data->next;

        previous->next = next;
        next->previous = previous;

        DLL* last = tail->previous;
        last->next = data;
        data->previous = last;
        data->next = tail;
        tail->previous = data;
    }

    int get(int key) {
        if(!cache.count(key))
            return -1;
        DLL* data = cache[key];
        adjust(data);
        return data->value;
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            DLL* data = cache[key];
            data->value = value;
            adjust(data);
            return;
        }

        DLL* previous = tail->previous;
        DLL* newNode = new DLL(key, value, previous, tail);
        tail->previous = newNode;
        previous->next = newNode;      

        if(cache.size()==capacity) {
            // Evict
            DLL* toRemove = head->next;
            head->next = toRemove->next;
            toRemove->next->previous = head;

            int key = toRemove->key;
            cache.erase(key);

            delete toRemove;
            toRemove = nullptr;            
        }
        cache[key] = newNode;
    }
    
};

int main() {

}


/*

["LRUCache","put","put","put","put","get","get"]
[[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]

Use Testcase
Output
[null,null,null,null,null,1,-1]

Expected
[null,null,null,null,null,-1,3]

*/


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */