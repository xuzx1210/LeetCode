class Solution
{
public:
    string frequencySort(string s)
    {
        const size_t range = 'z' - '0' + 1;
        vector<pair<int, char>> frequency(range);
        for (size_t i = 0; i < range; ++i)
            frequency[i].second = i + '0';
        for (char c : s)
            ++frequency[c - '0'].first;
        sort(frequency.begin(), frequency.end(), greater<pair<int, char>>());
        string result;
        for (size_t i = 0; i < range; ++i)
            result.insert(result.end(), frequency[i].first, frequency[i].second);
        return result;
    }
};
