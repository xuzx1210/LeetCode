class MyHashSet
{
public:
    vector<bool> hashset;
    MyHashSet()
    {
        hashset.resize(1000001, false);
    }
    void add(int key)
    {
        hashset[key] = true;
    }
    void remove(int key)
    {
        hashset[key] = false;
    }
    bool contains(int key)
    {
        return hashset[key];
    }
};
