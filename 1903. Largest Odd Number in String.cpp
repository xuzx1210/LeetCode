class Solution
{
public:
    string largestOddNumber(string num)
    {
        while (!num.empty() && (num.back() & 1) == 0)
            num.pop_back();
        return num;
    }
};
