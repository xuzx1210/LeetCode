class RandomizedCollection
{
private:
    unordered_map<int, vector<int>> indices; // key: val, value: all indices for val in vals
    vector<pair<int, int>> vals;             // first: val, second: index in indices[val]

public:
    RandomizedCollection()
    {
    }
    bool insert(int val)
    {
        vals.emplace_back(val, indices[val].size());
        indices[val].emplace_back(vals.size() - 1);
        return indices[val].size() == 1;
    }
    bool remove(int val)
    {
        if (indices[val].empty())
            return false;
        pair<int, int> last(vals.back());
        indices[last.first][last.second] = indices[val].back();
        vals[indices[val].back()] = last;
        indices[val].pop_back();
        vals.pop_back();
        return true;
    }
    int getRandom()
    {
        return vals[rand() % vals.size()].first;
    }
};
