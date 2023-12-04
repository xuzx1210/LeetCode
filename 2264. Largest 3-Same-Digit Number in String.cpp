class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int digit = -1;
        vector<int> counter(10, 0);
        ++counter[num[0] - '0'];
        ++counter[num[1] - '0'];
        for (int left = 0, right = 2, length = num.length(); right < length; ++left, ++right)
        {
            const int curr = num[right] - '0';
            if (++counter[curr] == 3)
                digit = max(digit, curr);
            --counter[num[left] - '0'];
        }
        return digit == -1 ? "" : string(3, digit + '0');
    }
};
