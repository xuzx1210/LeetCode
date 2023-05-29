class ParkingSystem
{
private:
    array<int, 3> capacity;

public:
    ParkingSystem(int big, int medium, int small)
    {
        capacity = {big, medium, small};
    }
    bool addCar(int carType)
    {
        return capacity[carType - 1] ? capacity[carType - 1]-- : false;
    }
};
