class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> count1, count2;
        for (int &num : nums1)
            ++count1[num];
        for (int &num : nums2)
            ++count2[num];
        vector<int> result;
        for (auto &[key, value] : count1)
            result.insert(result.end(), min(value, count2[key]), key);
        return result;
    }
};
