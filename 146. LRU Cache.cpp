class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;
    vector<optional<list<pair<int, int>>::iterator>> position;

public:
    LRUCache(int capacity) : capacity(capacity), cache{}, position(10001, nullopt) {}
    int get(int key)
    {
        if (!position[key])
            return -1;
        cache.splice(cache.begin(), cache, position[key].value());
        return cache.begin()->second;
    }
    void put(int key, int value)
    {
        if (position[key])
        {
            cache.splice(cache.begin(), cache, position[key].value());
            cache.begin()->second = value;
            return;
        }
        if (cache.size() == capacity)
        {
            position[cache.back().first] = nullopt;
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        position[key] = cache.begin();
    }
};
