class Solution
{
private:
    size_t mismatch;
    void insert(int &count)
    {
        if (count == 0)
            ++mismatch;
        ++count;
        if (count == 0)
            --mismatch;
    }
    void remove(int &count)
    {

        if (count == 0)
            ++mismatch;
        --count;
        if (count == 0)
            --mismatch;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        const size_t sLength = s.length(), pLength = p.length();
        vector<int> result{};
        if (sLength < pLength)
            return result;
        array<int, 26> counter = {0};
        mismatch = 0;
        for (size_t i = 0; i < pLength; ++i)
            remove(counter[p[i] - 'a']);
        for (size_t i = 0; i < pLength; ++i)
            insert(counter[s[i] - 'a']);
        if (mismatch == 0)
            result.emplace_back(0);
        for (size_t i = pLength; i < sLength; ++i)
        {
            insert(counter[s[i] - 'a']);
            remove(counter[s[i - pLength] - 'a']);
            if (mismatch == 0)
                result.emplace_back(i + 1 - pLength);
        }
        return result;
    }
};
