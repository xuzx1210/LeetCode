class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> treeCount(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            int count = 0, half = i >> 1;
            for (int j = 0; j < half; ++j)
                count += (treeCount[j] * treeCount[i - 1 - j]);
            count <<= 1;
            if (i & 1)
                count += (treeCount[half] * treeCount[half]);
            treeCount[i] = count;
        }
        return treeCount[n];
    }
};
