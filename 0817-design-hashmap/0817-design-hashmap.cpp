class MyHashMap {
public:
    vector<int> m;
    MyHashMap() {
        for(int i=0; i<=1000000; i++)
            m.push_back(-1);
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) 
    {
        return m[key]; 
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};