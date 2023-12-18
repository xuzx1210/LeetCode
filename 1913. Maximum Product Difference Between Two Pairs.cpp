class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int w = 0, x = 0, y = INT_MAX, z = INT_MAX;
        for (const int num : nums)
        {
            if (x < num)
                x = num;
            if (w < x)
                swap(w, x);
            if (num < y)
                y = num;
            if (y < z)
                swap(y, z);
        }
        return w * x - y * z;
    }
};
