class SeatManager
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int minUnused;

public:
    SeatManager(int n)
    {
        minUnused = 1;
    }
    int reserve()
    {
        if (pq.empty())
            return minUnused++;
        int result = pq.top();
        pq.pop();
        return result;
    }
    void unreserve(int seatNumber)
    {
        pq.emplace(seatNumber);
    }
};
