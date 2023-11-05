class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int result = arr[0];
        for (int i = 1, wins = 0; i < arr.size() && wins < k; ++i)
            if (result < arr[i])
            {
                result = arr[i];
                wins = 1;
            }
            else
                ++wins;
        return result;
    }
};
