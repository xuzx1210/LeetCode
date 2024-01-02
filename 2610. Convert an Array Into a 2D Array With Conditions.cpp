class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        const int size = nums.size();
        vector<int> frequencies(size + 1, 0);
        for (const int num : nums)
            ++frequencies[num];
        vector<vector<int>> result(*max_element(frequencies.begin(), frequencies.end()), vector<int>{});
        for (int i = 0; i <= size; ++i)
            for (int j = 0; j < frequencies[i]; ++j)
                result[j].emplace_back(i);
        return result;
    }
};
