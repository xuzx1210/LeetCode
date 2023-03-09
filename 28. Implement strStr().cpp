class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        const int haystackLength = haystack.length(), needleLength = needle.length();
        vector<int> failure(needleLength, 0);
        for (int index = 1, length = 0; index < needleLength;)
            if (needle[length] == needle[index])
                failure[index++] = ++length;
            else if (length)
                length = failure[length - 1];
            else
                failure[index++] = 0;
        for (int haystackIndex = 0, needleIndex = 0; haystackIndex < haystackLength;)
        {
            if (haystack[haystackIndex] == needle[needleIndex])
            {
                ++haystackIndex;
                ++needleIndex;
            }
            else if (needleIndex)
                needleIndex = failure[needleIndex - 1];
            else
                ++haystackIndex;
            if (needleIndex == needleLength)
                return haystackIndex - needleIndex;
        }
        return -1;
    }
};
