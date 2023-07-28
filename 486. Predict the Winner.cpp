class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        const int size = nums.size();
        vector<vector<pair<int, int>>> score(size, vector<pair<int, int>>(size));
        for (int i = 0; i < size; ++i)
            score[i][i] = {nums[i], nums[i]};
        for (int length = 2; length <= size; ++length)
            for (int front = 0, back = length - 1; back < size; ++front, ++back)
                score[front][back] = {
                    max(nums[front] - score[front + 1][back].second, nums[back] - score[front][back - 1].second),
                    max(nums[front] - score[front + 1][back].first, nums[back] - score[front][back - 1].first)};
        return score[0][size - 1].first >= 0;
    }
};
