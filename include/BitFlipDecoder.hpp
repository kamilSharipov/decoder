#pragma once

#include "AbstractDecoder.hpp"

#include <cstdint>

namespace LDPCpp {

class BitFlipDecoder : public AbstractDecoder {
private:
    std::uint32_t m_num_of_iterations;

public:
    explicit BitFlipDecoder(
        std::vector<std::vector<int>>& H
        , std::uint32_t num_of_iterations) noexcept;
    std::vector<int> decode(const std::vector<int>& received) override;
};
  
} // namespace LDPCpp
