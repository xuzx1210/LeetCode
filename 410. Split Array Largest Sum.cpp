class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int left = 0, right = 1;
        for (int num : nums)
        {
            left = max(left, num);
            right += num;
        }
        while (left < right)
        {
            const int middle = (left + right) >> 1;
            int counter = 1, sum = 0;
            for (int num : nums)
            {
                sum += num;
                if (middle < sum)
                {
                    sum = num;
                    ++counter;
                }
            }
            if (k < counter)
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};
