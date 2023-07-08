class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        long long result = 0;
        const int size = weights.size() - 1;
        --k;
        for (int i = 0; i < size; ++i)
            weights[i] += weights[i + 1];
        weights.pop_back();
        nth_element(weights.begin(), weights.begin() + k, weights.end());
        for (int i = 0; i < k; ++i)
            result -= weights[i];
        nth_element(weights.begin(), weights.begin() + size - k, weights.end());
        for (int i = size - k; i < size; ++i)
            result += weights[i];
        return result;
    }
};
