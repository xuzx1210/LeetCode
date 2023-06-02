class LFUCache
{
private:
    int capacity, minimumFrequency;
    unordered_map<int, pair<int, int>> key2data; //{value, frequency}
    unordered_map<int, list<int>::iterator> key2position;
    unordered_map<int, list<int>> frequency2key;
    void increaseFrequency(const int key)
    {
        frequency2key[key2data[key].second].erase(key2position[key]);
        ++key2data[key].second;
        frequency2key[key2data[key].second].emplace_front(key);
        key2position[key] = frequency2key[key2data[key].second].begin();
        if (frequency2key[minimumFrequency].empty())
            minimumFrequency++;
    }

public:
    LFUCache(int capacity) : capacity(capacity), minimumFrequency(0), key2data{}, key2position{}, frequency2key{} {}
    int get(int key)
    {
        if (key2data.find(key) == key2data.end())
            return -1;
        increaseFrequency(key);
        return key2data[key].first;
    }
    void put(int key, int value)
    {
        if (key2data.find(key) != key2data.end())
        {
            key2data[key].first = value;
            increaseFrequency(key);
            return;
        }
        if (key2data.size() == capacity)
        {
            const int removeKey = frequency2key[minimumFrequency].back();
            key2data.erase(removeKey);
            key2position.erase(removeKey);
            frequency2key[minimumFrequency].pop_back();
        }
        key2data[key] = {value, 1};
        frequency2key[1].emplace_front(key);
        key2position[key] = frequency2key[1].begin();
        minimumFrequency = 1;
    }
};
