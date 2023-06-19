class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        const int n = gain.size();
        int result = 0, altitude = 0;
        for (int i = 0; i < n; ++i)
        {
            altitude += gain[i];
            result = max(result, altitude);
        }
        return result;
    }
};
