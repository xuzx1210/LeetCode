class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        const size_t size = gas.size();
        int minimum = INT_MAX, tank = 0, result;
        for (size_t i = 0; i < size; ++i)
        {
            tank += gas[i];
            tank -= cost[i];
            if (tank < minimum)
            {
                minimum = tank;
                result = i;
            }
        }
        if (tank < 0)
            return -1;
        ++result;
        return result == size ? 0 : result;
    }
};
