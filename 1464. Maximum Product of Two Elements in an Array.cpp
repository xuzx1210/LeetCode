class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int first = 0, second = 0;
        for (const int num : nums)
        {
            if (second < num)
                second = num;
            if (first < second)
                swap(first, second);
        }
        return (first - 1) * (second - 1);
    }
};
