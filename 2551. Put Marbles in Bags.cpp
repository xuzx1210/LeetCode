class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        const int size = weights.size() - 1;
        for (int i = 0; i < size; ++i)
            weights[i] += weights[i + 1];
        weights.pop_back();
        long long result = 0;
        nth_element(weights.begin(), weights.begin() + k - 1, weights.end());
        for (int i = 0; i < k - 1; ++i)
            result -= weights[i];
        nth_element(weights.begin(), weights.begin() + size - k + 1, weights.end());
        for (int i = size - k + 1; i < size; ++i)
            result += weights[i];
        return result;
    }
};
