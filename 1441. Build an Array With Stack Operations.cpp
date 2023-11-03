class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        const int targetSize = target.size();
        vector<string> result((target.back() << 1) - targetSize);
        for (int stream = 1, targetIndex = 0, resultIndex = 0; targetIndex < targetSize; ++targetIndex)
        {
            for (; stream < target[targetIndex]; ++stream)
            {
                result[resultIndex++] = "Push";
                result[resultIndex++] = "Pop";
            }
            result[resultIndex++] = "Push";
            ++stream;
        }
        return result;
    }
};
