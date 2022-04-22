class MyHashMap
{
public:
    vector<int> hashmap;
    MyHashMap()
    {
        hashmap.resize(1000001, -1);
    }
    void put(int key, int value)
    {
        hashmap[key] = value;
    }
    int get(int key)
    {
        return hashmap[key];
    }
    void remove(int key)
    {
        hashmap[key] = -1;
    }
};
