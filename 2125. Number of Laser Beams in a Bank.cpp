class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int result = 0;
        vector<int> deviceCounts{};
        for (int i = bank.size() - 1; i >= 0; --i)
        {
            const int devices = count(bank[i].begin(), bank[i].end(), '1');
            if (devices)
                deviceCounts.emplace_back(devices);
        }
        for (int i = deviceCounts.size() - 2; i >= 0; --i)
            result += deviceCounts[i] * deviceCounts[i + 1];
        return result;
    }
};
