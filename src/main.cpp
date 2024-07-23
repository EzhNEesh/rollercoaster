#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "binaryreader.h"
#include "normaldistribution.h"
#include "rollercoaster.h"

using namespace std;

int main(int argc, char *argv[])
{
    BinaryReader binReader;
    vector<float> nums = binReader.readBinary(argv[1]);

    NormalDistribution nDistribution{nums};
    int noizeFloor = nDistribution.getBorders().second;

    RollerCoaster rollerCoaster{nums};
    vector<pair<unsigned int, unsigned int>> results = rollerCoaster.findRollerCoasters(atoi(argv[3]), atoi(argv[4]), noizeFloor);

    ofstream file(argv[2]);
    if (file.is_open()) {
        for (unsigned int i = 0; i < results.size(); i++) {
            file << results[i].first << ' ' << results[i].second << endl;
        }
    }
    return 0;
}
