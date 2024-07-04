#include<iostream>
#include<vector>

using namespace std;

const int HMAP_SIZE = 1000;

struct LinkedList {
    int key;
    int value;

    LinkedList(int key, int value): key(key), value(value) {}
};

class Mapper {
    private:
    vector<vector<LinkedList>> store;

    int hashFunction(int key) {
        return key%HMAP_SIZE;
    }

    public:
    Mapper() {
        store = vector<vector<LinkedList>>(HMAP_SIZE);
    }    

    public:
    void put(int key, int value) {
        int hash = hashFunction(key);
        vector<LinkedList> tmp = store[hash];
        
        for(LinkedList& tmp: store[hash]) {
            if(tmp.key==key) {
                tmp.value = value;
                return;                
            }
        }
        store[hash].push_back(LinkedList(key, value));        
    }

    int get(int key) {
        int hash = hashFunction(key);
        vector<LinkedList>& bucket = store[hash];
        if(bucket.size()==0)
            return 0;
        for(LinkedList node: bucket) {
            if(node.key==key)
                return node.value;
        }
        return 0;
    }
};

int main() {

    Mapper mapper = Mapper();
    cout<<"get(1)="<<mapper.get(1)<<endl;
    mapper.put(1, 2);
    cout<<"get(1)="<<mapper.get(1)<<endl;
    
    cout<<"get(1001)="<<mapper.get(1001)<<endl;
    mapper.put(1001, 10);
    cout<<"get(1001)="<<mapper.get(1001)<<endl;

    return 0;
}