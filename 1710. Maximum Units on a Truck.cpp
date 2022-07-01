class Solution
{
private:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int result = 0;
        for (auto &boxes : boxTypes)
            if (truckSize >= boxes[0])
            {
                result += boxes[0] * boxes[1];
                truckSize -= boxes[0];
            }
            else
            {
                result += truckSize * boxes[1];
                break;
            }
        return result;
    }
};
