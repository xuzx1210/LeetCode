class Solution
{
private:
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 == hash2 ? hash1 : hash1 ^ hash2;
        }
    };
    unordered_map<pair<int, int>, int, hash_pair> dp;
    unordered_map<int, int> successorIndices;
    int size1, size2;
    int dfs(const int index, const int previous, const vector<int> &arr1, const vector<int> &arr2)
    {
        if (index == size1)
            return 0;
        if (dp.find({index, previous}) != dp.end())
            return dp[{index, previous}];
        int change = 2001, keep = 2001;
        const int successorIndex = successorIndices[previous];
        if (successorIndex < size2)
            change = 1 + dfs(index + 1, arr2[successorIndex], arr1, arr2);
        if (previous < arr1[index])
            keep = dfs(index + 1, arr1[index], arr1, arr2);
        dp[{index, previous}] = min(change, keep);
        return dp[{index, previous}];
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        size1 = arr1.size();
        size2 = arr2.size();
        dp.clear();
        successorIndices.clear();
        successorIndices[-1] = 0;
        for (const int num : arr1)
            successorIndices[num] = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
        for (const int num : arr2)
            successorIndices[num] = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
        int result = dfs(0, -1, arr1, arr2);
        return result > size1 ? -1 : result;
    }
};
