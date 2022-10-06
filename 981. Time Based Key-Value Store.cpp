class TimeMap
{
private:
    unordered_map<string, map<int, string>> timeMap;

public:
    TimeMap()
    {
        timeMap.clear();
    }
    void set(string key, string value, int timestamp)
    {
        timeMap[key][timestamp] = value;
    }
    string get(string key, int timestamp)
    {
        auto it = timeMap[key].lower_bound(timestamp);
        if (it->first == timestamp)
            return it->second;
        if (it == timeMap[key].begin())
            return "";
        return (--it)->second;
    }
};
