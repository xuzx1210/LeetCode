class Solution
{
private:
    array<size_t, 26> root;
    size_t findRoot(size_t x)
    {
        if (x == root[x])
            return x;
        return root[x] = findRoot(root[x]);
    }
    void setUnion(size_t x, size_t y)
    {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y)
            return;
        if (x > y)
            swap(x, y);
        root[y] = x;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        iota(root.begin(), root.end(), 0);
        const size_t length = s1.length();
        for (size_t i = 0; i < length; ++i)
            setUnion(s1[i] - 'a', s2[i] - 'a');
        for (char &c : baseStr)
            c = findRoot(c - 'a') + 'a';
        return baseStr;
    }
};
