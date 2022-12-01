class Solution
{
private:
    void fullAdder(char a, char b, int &carry, string &result)
    {
        const int sum = (a - '0') + (b - '0') + carry;
        if (sum < 10)
        {
            carry = 0;
            result.push_back(sum + '0');
        }
        else
        {
            carry = 1;
            result.push_back(sum - 10 + '0');
        }
    }

public:
    string addStrings(string num1, string num2)
    {
        const size_t length1 = num1.length(), length2 = num2.length();
        const size_t minLength = min(length1, length2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        string result;
        for (size_t i = 0; i < minLength; ++i)
            fullAdder(num1[i], num2[i], carry, result);
        if (length1 > length2)
            for (size_t i = length2; i < length1; ++i)
                fullAdder(num1[i], '0', carry, result);
        else
            for (size_t i = length1; i < length2; ++i)
                fullAdder('0', num2[i], carry, result);
        if (carry)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
