class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, bool> exist1, exist2;
        for (int &num : nums1)
            exist1[num] = true;
        for (int &num : nums2)
            exist2[num] = true;
        vector<int> result;
        for (auto &[key, value] : exist1)
            if (exist2[key])
                result.emplace_back(key);
        return result;
    }
};
