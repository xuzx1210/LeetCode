class Solution
{
public:
    int minDeletions(string s)
    {
        int result = 0;
        vector<int> frequency(26, 0);
        for (const char c : s)
            ++frequency[c - 'a'];
        sort(frequency.begin(), frequency.end());
        for (int i = 24; i >= 0; --i)
        {
            if (frequency[i] == 0)
                break;
            if (frequency[i] < frequency[i + 1])
                continue;
            const int target = max(0, frequency[i + 1] - 1);
            result += frequency[i] - target;
            frequency[i] = target;
        }
        return result;
    }
};
