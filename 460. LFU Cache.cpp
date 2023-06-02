class LFUCache
{
private:
    class Data
    {
    public:
        int value, frequency;
        void set(const int value, const int frequency)
        {
            this->value = value;
            this->frequency = frequency;
        }
    };
    int capacity, minimumFrequency;
    unordered_map<int, Data> key2data;
    unordered_map<int, list<int>::iterator> key2position;
    unordered_map<int, list<int>> frequency2key;
    void increaseFrequency(const int key)
    {
        frequency2key[key2data[key].frequency].erase(key2position[key]);
        if (frequency2key[key2data[key].frequency].empty())
        {
            frequency2key.erase(key2data[key].frequency);
            if (key2data[key].frequency == minimumFrequency)
                ++minimumFrequency;
        }
        ++key2data[key].frequency;
        frequency2key[key2data[key].frequency].emplace_front(key);
        key2position[key] = frequency2key[key2data[key].frequency].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minimumFrequency(0), key2data{}, key2position{}, frequency2key{} {}
    int get(int key)
    {
        if (key2data.find(key) == key2data.end())
            return -1;
        increaseFrequency(key);
        return key2data[key].value;
    }
    void put(int key, int value)
    {
        if (key2data.find(key) != key2data.end())
        {
            key2data[key].value = value;
            increaseFrequency(key);
            return;
        }
        if (key2data.size() == capacity)
        {
            const int removeKey = frequency2key[minimumFrequency].back();
            key2data.erase(removeKey);
            key2position.erase(removeKey);
            frequency2key[minimumFrequency].pop_back();
            if (frequency2key[minimumFrequency].empty())
                frequency2key.erase(minimumFrequency);
        }
        key2data[key].set(value, 1);
        frequency2key[1].emplace_front(key);
        key2position[key] = frequency2key[1].begin();
        minimumFrequency = 1;
    }
};
