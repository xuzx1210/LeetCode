class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), (long long)0);
        const int size = batteries.size();
        int index = 0;
        for (int back = size - 1; batteries[back] > sum / (n - index); ++index, --back)
            sum -= batteries[back];
        return sum / (n - index);
    }
};
