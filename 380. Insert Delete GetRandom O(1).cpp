class RandomizedSet
{
private:
    unordered_map<int, int> positions;
    vector<int> randomizedSet;

public:
    RandomizedSet()
    {
        positions.clear();
        randomizedSet.clear();
    }
    bool insert(int val)
    {
        if (positions.find(val) != positions.end())
            return false;
        positions[val] = randomizedSet.size();
        randomizedSet.emplace_back(val);
        return true;
    }
    bool remove(int val)
    {
        if (positions.find(val) == positions.end())
            return false;
        const int position = positions[val], back = randomizedSet.back();
        positions[back] = position;
        positions.erase(val);
        randomizedSet[position] = back;
        randomizedSet.pop_back();
        return true;
    }
    int getRandom()
    {
        return randomizedSet[rand() % randomizedSet.size()];
    }
};
