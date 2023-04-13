class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int pushIndex = 0, popIndex = 0;
        for (int num : pushed)
        {
            pushed[pushIndex] = num;
            while (-1 < pushIndex && pushed[pushIndex] == popped[popIndex])
            {
                --pushIndex;
                ++popIndex;
            }
            ++pushIndex;
        }
        return !pushIndex;
    }
};
