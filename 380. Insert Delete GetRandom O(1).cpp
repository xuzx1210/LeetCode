class RandomizedSet
{
private:
    unordered_map<int, int> index; // key: val, value: index of val in vals + 1(0 for not exist in vals)
    vector<int> vals;

public:
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (index[val])
            return false;
        vals.emplace_back(val);
        index[val] = vals.size();
        return true;
    }
    bool remove(int val)
    {
        if (!index[val])
            return false;
        vals[index[val] - 1] = vals.back();
        index[vals.back()] = index[val];
        index[val] = 0;
        vals.pop_back();
        return true;
    }
    int getRandom()
    {
        return vals[rand() % vals.size()];
    }
};
