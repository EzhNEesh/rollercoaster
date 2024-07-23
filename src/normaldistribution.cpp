#include "normaldistribution.h"

NormalDistribution::NormalDistribution(const std::vector<float> &nums) {
    for (auto it=nums.begin(); it!=nums.end(); it++) {
        int rounded = roundf(*it);
        if (distribution.find(rounded) == distribution.end()) {
            distribution[rounded] = 0;
        }
        distribution[rounded] += 1;
    }
    totalCount = nums.size();

    moda = distribution.begin()->first;
    int modaValue = distribution.begin()->second;
    for (auto it=distribution.begin(); it!=distribution.end(); it++) {
        if (it->second > modaValue) {
            moda = it->first;
            modaValue = it->second;
        }
    }
}

std::pair<int, int> NormalDistribution::getBorders() {
    int left = moda;
    int right = moda;
    while (100. * distribution[left] / totalCount + 100. * distribution[right] / totalCount > 2) {
        left--;
        right++;
    }
    return std::pair<int, int> (left, right);
}
