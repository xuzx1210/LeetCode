class Solution
{
private:
    char fullAdder(char aIn, char bIn, bool &carry)
    {
        bool a = aIn - '0', b = bIn - '0';
        bool c = a ^ b ^ carry;
        carry = a && b || a && carry || b && carry;
        return c + '0';
    }

public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        const int aLength = a.length(), bLength = b.length();
        const int minLength = min(aLength, bLength);
        bool carry = false;
        string result("");
        for (int i = 0; i < minLength; ++i)
            result.push_back(fullAdder(a[i], b[i], carry));
        if (aLength < bLength)
            for (int i = aLength; i < bLength; ++i)
                result.push_back(fullAdder('0', b[i], carry));
        else
            for (int i = bLength; i < aLength; ++i)
                result.push_back(fullAdder(a[i], '0', carry));
        if (carry)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
