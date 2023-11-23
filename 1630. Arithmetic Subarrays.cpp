class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        const int n = nums.size(), m = l.size();
        vector<bool> answer(m);
        for (int query = 0; query < m; ++query)
        {
            const int left = l[query], right = r[query] + 1;
            auto [minIt, maxIt] = minmax_element(nums.begin() + left, nums.begin() + right);
            const int minimum = *minIt, maximum = *maxIt;
            if (minimum == maximum)
            {
                answer[query] = true;
                continue;
            }
            const int length = right - left, range = length - 1;
            const int totalDifference = maximum - minimum, commonDifference = totalDifference / range;
            if (totalDifference % range != 0)
            {
                answer[query] = false;
                continue;
            }
            vector<bool> existence(length, false);
            int i;
            for (i = left; i < right; ++i)
            {
                const int index = (nums[i] - minimum) / commonDifference;
                if ((nums[i] - minimum) % commonDifference != 0 || existence[index])
                    break;
                existence[index] = true;
            }
            answer[query] = i == right;
        }
        return answer;
    }
};
