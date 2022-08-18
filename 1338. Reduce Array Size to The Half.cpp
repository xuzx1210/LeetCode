class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int half = arr.size() >> 1;
        unordered_map<int, int> counter = {};
        for (int &num : arr)
            ++counter[num];
        vector<int> descending = {};
        for (auto &c : counter)
            descending.push_back(c.second);
        sort(descending.rbegin(), descending.rend());
        int size = descending.size();
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += descending[i];
            if (sum >= half)
                return i + 1;
        }
        return size;
    }
};
