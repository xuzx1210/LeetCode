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
class MyHashSet
{
private:
    int prime;
    vector<list<int>> table;
    list<int>::iterator position;
    void search(const int h, const int key)
    {
        position = find(table[h].begin(), table[h].end(), key);
    }

public:
    MyHashSet() : prime(1009), table(prime, list<int>{}) {}
    void add(int key)
    {
        if (contains(key))
            return;
        table[key % prime].emplace_back(key);
    }
    void remove(int key)
    {
        if (!contains(key))
            return;
        const int h = key % prime;
        table[h].erase(position);
    }
    bool contains(int key)
    {
        const int h = key % prime;
        search(h, key);
        return position != table[h].end();
    }
};
