class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        const int size = capacity.size();
        for (int i = 0; i < size; ++i)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int result = 0;
        while (result < size && additionalRocks >= capacity[result])
            additionalRocks -= capacity[result++];
        return result;
    }
};
