class Solution
{
private:
    size_t match;
    void insertRight(int &count)
    {
        if (count == 0)
            --match;
        ++count;
        if (count == 0)
            ++match;
    }
    void removeLeft(int &count)
    {
        if (count == 0)
            --match;
        --count;
        if (count == 0)
            ++match;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        const size_t length1 = s1.length(), length2 = s2.length();
        if (length1 > length2)
            return false;
        array<int, 26> counter = {0};
        for (const char c : s1)
            --counter[c - 'a'];
        match = 0;
        for (size_t i = 0; i < 26; ++i)
            if (counter[i] == 0)
                ++match;
        for (size_t i = 0; i < length1; ++i)
            insertRight(counter[s2[i] - 'a']);
        if (match == 26)
            return true;
        for (size_t i = length1; i < length2; ++i)
        {
            insertRight(counter[s2[i] - 'a']);
            removeLeft(counter[s2[i - length1] - 'a']);
            if (match == 26)
                return true;
        }
        return false;
    }
};
