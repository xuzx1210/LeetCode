class RandomizedSet
{
private:
    unordered_map<int, int> indices;
    vector<int> vals;

public:
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (indices[val])
            return false;
        vals.emplace_back(val);
        indices[val] = vals.size();
        return true;
    }
    bool remove(int val)
    {
        if (!indices[val])
            return false;
        vals[indices[val] - 1] = vals.back();
        indices[vals.back()] = indices[val];
        indices[val] = 0;
        vals.pop_back();
        return true;
    }
    int getRandom()
    {
        return vals[rand() % vals.size()];
    }
};
