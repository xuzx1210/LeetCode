class Solution
{
private:
    int ones(int num)
    {
        int result = 0;
        for (; num; num &= (num - 1))
            ++result;
        return result;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        auto compare = [&](int a, int b)
        {
            int aOnes = ones(a), bOnes = ones(b);
            if (aOnes < bOnes)
                return true;
            if (aOnes > bOnes)
                return false;
            return a < b;
        };
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
