class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        const int n = edges.size();
        int result = -1;
        vector<int> nodeIndex(n, 0);
        int index = 1;
        for (int pathBegin = 0; pathBegin < n; ++pathBegin)
        {
            const int startIndex = index;
            for (int node = pathBegin; node != -1; node = edges[node])
            {
                if (nodeIndex[node] >= startIndex) // is cycle
                {
                    result = max(result, index - nodeIndex[node]);
                    break;
                }
                if (nodeIndex[node]) // visited before
                    break;
                nodeIndex[node] = index++;
            }
        }
        return result;
    }
};
