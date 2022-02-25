class Solution
{
public:
    char addDigit(char a, char b, int &carry)
    {
        int sum = a + b - ('0' << 1) + carry;
        carry = sum >> 1;
        return (sum & 1) + '0';
    }
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int aLength = a.length(), bLength = b.length();
        int minLength = min(aLength, bLength);
        string result("");
        int carry = 0;
        for (int i = 0; i < minLength; ++i)
            result.push_back(addDigit(a[i], b[i], carry));
        if (aLength < bLength)
            for (int i = minLength; i < bLength; ++i)
                result.push_back(addDigit('0', b[i], carry));
        else
            for (int i = minLength; i < aLength; ++i)
                result.push_back(addDigit(a[i], '0', carry));
        if (carry)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
