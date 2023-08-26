class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int result = 0;
        sort(pairs.begin(), pairs.end());
        int last = -1001;
        for (const vector<int> &pair : pairs)
            if (last < pair[0])
            {
                ++result;
                last = pair[1];
            }
            else
                last = min(last, pair[1]);
        return result;
    }
};
