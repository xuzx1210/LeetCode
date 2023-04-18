class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        const int length1 = word1.length(), length2 = word2.length();
        const int length = length1 + length2;
        string result(word1 + word2);
        for (int i = 0, j = 0, index = 0; index < length; ++index)
            if (i == length1)
                result[index] = word2[j++];
            else if (j == length2)
                result[index] = word1[i++];
            else
                result[index] = (index & 1) ? word2[j++] : word1[i++];
        return result;
    }
};
