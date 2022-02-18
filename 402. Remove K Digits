class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.length())
            return "0";
        if (k == 0)
            return num;
        for (int i = 0; i < num.length() - 1; ++i)
            if (num[i] > num[i + 1])
            {
                num.erase(num.begin() + i);
                if ((--k) == 0)
                    break;
                i = max(i - 2, -1);
            }
        for (int i = 0; i < k; ++i)
            num.pop_back();
        while (num.length() > 1 && num[0] == '0')
            num.erase(num.begin());
        return num;
    }
};
