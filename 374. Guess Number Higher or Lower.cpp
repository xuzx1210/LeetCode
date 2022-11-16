class Solution
{
public:
    int guessNumber(int n)
    {
        int picked;
        for (int left = 1, right = n; left <= right;)
        {
            int num = (left >> 1) + (right >> 1);
            if (left & right & 1)
                ++num;
            int result = guess(num);
            if (result == -1)
                right = num - 1;
            else if (result == 1)
                left = num + 1;
            else
            {
                picked = num;
                break;
            }
        }
        return picked;
    }
};
