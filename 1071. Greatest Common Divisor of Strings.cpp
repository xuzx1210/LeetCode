class Solution
{
private:
    size_t euclidean(const size_t length1, const size_t length2)
    {
        if (length1 == 0)
            return length2;
        return euclidean(length2 % length1, length1);
    }

public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        const size_t gcd = euclidean(str1.length(), str2.length());
        return str1.substr(0, gcd);
    }
};
