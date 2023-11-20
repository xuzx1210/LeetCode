class Solution
{
private:
    int collect(const vector<string> &garbage, const vector<int> &travel, const char type)
    {
        int last = -1;
        for (int i = garbage.size() - 1; i >= 0; --i)
            if (find(garbage[i].begin(), garbage[i].end(), type) != garbage[i].end())
            {
                last = i;
                break;
            }
        if (last == -1)
            return 0;
        int result = 0;
        for (int i = 0; i < last; ++i)
        {
            result += count(garbage[i].begin(), garbage[i].end(), type);
            result += travel[i];
        }
        result += count(garbage[last].begin(), garbage[last].end(), type);
        return result;
    }

public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        return collect(garbage, travel, 'M') + collect(garbage, travel, 'P') + collect(garbage, travel, 'G');
    }
};
