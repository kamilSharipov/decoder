#pragma once

#include <vector>

namespace LDPCpp {

class AbstractDecoder {
public:
    virtual std::vector<int> decode(const std::vector<int>& received_code) = 0;    
    virtual ~AbstractDecoder() = default;
};

} // namespace LDPCpp
