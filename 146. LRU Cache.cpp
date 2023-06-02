class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> values;
    unordered_map<int, list<pair<int, int>>::iterator> position;

public:
    LRUCache(int capacity) : capacity(capacity), values{}, position{} {}
    int get(int key)
    {
        if (position.find(key) == position.end())
            return -1;
        values.splice(values.begin(), values, position[key]);
        return position[key]->second;
    }
    void put(int key, int value)
    {
        if (position.find(key) != position.end())
        {
            values.splice(values.begin(), values, position[key]);
            position[key]->second = value;
            return;
        }
        if (values.size() == capacity)
        {
            position.erase(values.back().first);
            values.pop_back();
        }
        values.emplace_front(key, value);
        position[key] = values.begin();
    }
};
