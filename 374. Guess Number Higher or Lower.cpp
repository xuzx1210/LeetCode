class Solution
{
public:
    int guessNumber(int n)
    {
        int result;
        for (int left = 1, right = n;;)
        {
            int mid = (left >> 1) + (right >> 1);
            if (left & right & 1)
                ++mid;
            int num = guess(mid);
            if (num == -1)
                right = mid - 1;
            else if (num == 1)
                left = mid + 1;
            else
            {
                result = mid;
                break;
            }
        }
        return result;
    }
};
