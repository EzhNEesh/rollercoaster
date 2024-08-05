#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include <vector>

class RollerCoaster
{
public:
    RollerCoaster(const std::vector<float> &nums);
    std::vector<std::pair<unsigned int, unsigned int>> findRollerCoasters(const unsigned int &minRange,
                                                                          const unsigned int &maxRange,
                                                                          const int &noizeFloor);

private:
    std::vector<float> nums;
};

#endif // ROLLERCOASTER_H
