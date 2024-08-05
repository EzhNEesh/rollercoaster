#ifndef NORMALDISTRIBUTION_H
#define NORMALDISTRIBUTION_H

#include <vector>
#include <map>

class NormalDistribution
{
public:
    NormalDistribution(const std::vector<float> &nums);
    std::pair<int, int> getBorders();

private:
    std::map<int, int> distribution;
    int totalCount;
    int moda;
};

#endif // NORMALDISTRIBUTION_H
