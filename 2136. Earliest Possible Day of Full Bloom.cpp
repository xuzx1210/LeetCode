class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int size = plantTime.size();
        vector<pair<int, int>> flower(size);
        for (int i = 0; i < size; ++i)
            flower[i] = {growTime[i], plantTime[i]};
        sort(flower.begin(), flower.end());
        int result = 0;
        for (int start = 0, i = size - 1; i >= 0; --i)
        {
            start += flower[i].second;
            result = max(result, start + flower[i].first);
        }
        return result;
    }
};
