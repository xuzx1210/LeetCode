class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int size = plantTime.size();
        vector<pair<int, int>> flower(size);
        for (int i = 0; i < size; ++i)
            flower[i] = {plantTime[i], growTime[i]};
        auto compare = [](pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second < b.second)
                return false;
            if (a.second > b.second)
                return true;
            return a.first < b.first;
        };
        sort(flower.begin(), flower.end(), compare);
        int result = 0;
        for (int start = 0, i = 0; i < size; ++i)
        {
            start += flower[i].first;
            result = max(result, start + flower[i].second);
        }
        return result;
    }
};
