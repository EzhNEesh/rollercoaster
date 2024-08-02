#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <vector>

class BinaryReader
{
public:
    BinaryReader();
    std::vector<float> readBinary(const std::string &);
};

#endif // BINARYREADER_H
