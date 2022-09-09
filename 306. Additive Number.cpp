class Solution
{
private:
    void add(string a, string b, string &result, int &carry)
    {
        int length = a.length();
        for (int i = 0; i < length; ++i)
        {
            int tmp = carry + (a[i] - '0') + (b[i] - '0');
            result.push_back(tmp % 10 + '0');
            carry = tmp / 10;
        }
    }
    string add(string a, string b)
    {
        if (a.length() < b.length())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int maxLength = a.length(), minLength = b.length(), carry = 0;
        string result = "";
        add(a.substr(0, minLength), b.substr(0, minLength), result, carry);
        add(a.substr(minLength, maxLength - minLength), string(maxLength - minLength, '0'), result, carry);
        if (carry)
            result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return result;
    }
    bool match(int len0, int len1, string &num)
    {
        string num0 = num.substr(0, len0), num1 = num.substr(len0, len1);
        int length = num.length(), start = len0 + len1;
        while (start < length)
        {
            string num2 = add(num0, num1);
            int len2 = num2.length();
            if (start + len2 > length)
                return false;
            if (num.substr(start, len2) != num2)
                return false;
            num0 = num1;
            num1 = num2;
            start += len2;
        }
        return true;
    }

public:
    bool isAdditiveNumber(string num)
    {
        int length = num.length();
        int half = length >> 1;
        for (int len0 = 1; len0 <= half; ++len0)
        {
            for (int len1 = 1; max(len0, len1) <= length - len0 - len1; ++len1)
            {
                if (match(len0, len1, num))
                    return true;
                if (num[len0] == '0')
                    break;
            }
            if (num[0] == '0')
                break;
        }
        return false;
    }
};
