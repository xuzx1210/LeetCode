class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices(plantTime.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return growTime[i] > growTime[j]; });
        int result = 0, startTime = 0;
        for (int index : indices) {
            startTime += plantTime[index];
            result = max(result, startTime + growTime[index]);
        }
        return result;
    }
};
