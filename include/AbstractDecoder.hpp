#pragma once

#include <vector>

namespace LDPCpp {

class AbstractDecoder {
public:
    [[nodiscard]] virtual std::vector<int> decode(const std::vector<int>& received_code) = 0;    
    virtual ~AbstractDecoder() = default;
};

} // namespace LDPCpp
