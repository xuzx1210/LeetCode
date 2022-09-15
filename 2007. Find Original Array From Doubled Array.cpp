class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int size = changed.size();
        if (size & 1)
            return {};
        map<int, int> counter{};
        for (int &num : changed)
            ++counter[num];
        vector<int> result{};
        result.insert(result.end(), counter[0] >> 1, 0);
        for (auto &[key, value] : counter)
        {
            if (!value)
                continue;
            int doubleKey = key << 1;
            if (counter[doubleKey] < value)
                return {};
            counter[doubleKey] -= value;
            result.insert(result.end(), value, key);
        }
        return result;
    }
};
