#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include <vector>
#include <iostream>

class RollerCoaster
{
public:
    RollerCoaster(const std::vector<float> &);
    std::vector<std::pair<unsigned int, unsigned int>> findRollerCoasters(const unsigned int &, const unsigned int &, const int &);

private:
    std::vector<float> nums;
};

#endif // ROLLERCOASTER_H
