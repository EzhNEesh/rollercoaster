#include <iostream>
#include <fstream>
#include <vector>

#include "binaryreader.h"
#include "normaldistribution.h"
#include "rollercoaster.h"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        std::cout << "Count of arguments must equal 5" << std::endl;
    }

    BinaryReader binReader;
    std::vector<float> nums;
    try {
        nums = binReader.readBinary(argv[1]);
    } catch (std::runtime_error &excp) {
        std::cout << excp.what() << std::endl;
        return 1;
    }

    NormalDistribution nDistribution{nums};
    int noizeFloor = nDistribution.getBorders().second;

    RollerCoaster rollerCoaster{nums};
    std::vector<std::pair<unsigned int, unsigned int>> results = rollerCoaster.findRollerCoasters(atoi(argv[3]), atoi(argv[4]), noizeFloor);

    std::ofstream file(argv[2]);
    if (file.is_open()) {
        for (unsigned int i = 0; i < results.size(); i++) {
            file << results[i].first << ' ' << results[i].second << std::endl;
        }
    }
    return 0;
}
