class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> occur(n);
        vector<int> result(2);
        for (int &num : nums)
        {
            if (occur[num - 1])
                result[0] = num;
            occur[num - 1] = true;
        }
        for (int i = 0; i < n; ++i)
            if (!occur[i])
            {
                result[1] = i + 1;
                break;
            }
        return result;
    }
};
