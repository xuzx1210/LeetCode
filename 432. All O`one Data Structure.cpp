class AllOne
{
private:
    unordered_map<string, int> counter;
    map<int, unordered_set<string>> sameCount;

public:
    AllOne()
    {
        counter.clear();
        sameCount.clear();
    }
    void inc(string key)
    {
        if (counter[key])
        {
            sameCount[counter[key]].erase(key);
            if (sameCount[counter[key]].empty())
                sameCount.erase(counter[key]);
            ++counter[key];
        }
        else
            counter[key] = 1;
        sameCount[counter[key]].insert(key);
    }
    void dec(string key)
    {
        sameCount[counter[key]].erase(key);
        if (sameCount[counter[key]].empty())
            sameCount.erase(counter[key]);
        if (--counter[key])
            sameCount[counter[key]].insert(key);
    }
    string getMaxKey()
    {
        return sameCount.empty() ? "" : *(sameCount.rbegin()->second.begin());
    }
    string getMinKey()
    {
        return sameCount.empty() ? "" : *(sameCount.begin()->second.begin());
    }
};
