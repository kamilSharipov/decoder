#pragma once

#include <vector>

namespace decoder {

class AbstractDecoder {
protected:
    std::vector<std::vector<int>> m_H;
public:
    explicit AbstractDecoder(std::vector<std::vector<int>>& H) noexcept : m_H(H) {}
    virtual std::vector<int> decode(const std::vector<int>& received_code) = 0;    
    virtual ~AbstractDecoder() = default;
};

} // namespace decoder
