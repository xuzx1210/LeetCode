class Solution
{
private:
    class Task
    {
    public:
        size_t enqueueTime, processingTime, index;
        void set(size_t s, size_t t, size_t i)
        {
            enqueueTime = s;
            processingTime = t;
            index = i;
        }
        bool operator<(const Task &right) const // two const are necessary, for priority_queue
        {
            if (processingTime > right.processingTime)
                return true;
            if (processingTime < right.processingTime)
                return false;
            return index > right.index;
        }
    };

public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        const size_t size = tasks.size();
        vector<Task> sortedByEnqueueTime(size);
        for (size_t i = 0; i < size; ++i)
            sortedByEnqueueTime[i].set(tasks[i][0], tasks[i][1], i);
        auto compareByEnqueueTime = [](const Task &a, const Task &b)
        {
            return a.enqueueTime < b.enqueueTime;
        };
        sort(sortedByEnqueueTime.begin(), sortedByEnqueueTime.end(), compareByEnqueueTime); // sort tasks by enqueueTime
        priority_queue<Task> pq{};
        vector<int> result(size);
        for (size_t timer = sortedByEnqueueTime[0].enqueueTime, enqueueIndex = 0, processIndex = 0; processIndex < size;)
        {
            while (enqueueIndex < size && sortedByEnqueueTime[enqueueIndex].enqueueTime <= timer) // if enqueueTime <= timer
                pq.emplace(sortedByEnqueueTime[enqueueIndex++]);
            if (pq.empty()) // if cpu is idle
            {
                timer = sortedByEnqueueTime[enqueueIndex].enqueueTime; // get next enqueueTime
                continue;
            }
            timer += pq.top().processingTime; // update timer
            result[processIndex++] = pq.top().index;
            pq.pop();
        }
        return result;
    }
};
