class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> outDegree(n, 0), inDegree(n, 0);
        for (const vector<int> &t : trust)
        {
            ++outDegree[t[0] - 1];
            ++inDegree[t[1] - 1];
        }
        int result = -1;
        for (int i = 0; i < n; ++i)
            if (outDegree[i] == 0 && inDegree[i] == n - 1)
                if (result == -1)
                    result = i + 1;
                else
                    return -1;
        return result;
    }
};
