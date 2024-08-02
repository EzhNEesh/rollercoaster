#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
        nums = binReader.getNumsFromBinary(argv[1]);
    } catch (std::runtime_error &excp) {
        std::cout << excp.what() << std::endl;
        return 1;
    }

    NormalDistribution nDistribution{nums};
    int noizeFloor = nDistribution.getBorders().second;

    RollerCoaster rollerCoaster{nums};
    std::vector<std::pair<unsigned int, unsigned int>> results;
    unsigned int minRange;
    unsigned int maxRange;

    try {
        size_t countConverted;

        minRange = std::stoi(argv[3], &countConverted);
        if (countConverted != strlen(argv[3])) {
            std::cout << "Min range must be unsigned integer" << std::endl;
            return 1;
        }

        maxRange = std::stoi(argv[4], &countConverted);
        if (countConverted != strlen(argv[4])) {
            std::cout << "Max range must be unsigned integer" << std::endl;
            return 1;
        }
    } catch (std::invalid_argument &excp){
        std::cout << excp.what() << std::endl;
        return 1;
    } catch (std::out_of_range){
        std::cout << "Cannot convert border" << std::endl;
        return 1;
    }
    try {
        results = rollerCoaster.findRollerCoasters(minRange, maxRange, noizeFloor);
    } catch (std::logic_error){
        std::cout << "Border number is too long " << std::endl;
    }

    std::ofstream file(argv[2]);
    if (file.is_open()) {
        for (unsigned int i = 0; i < results.size(); i++) {
            file << results[i].first << ' ' << results[i].second << std::endl;
        }
    }
    return 0;
}
