#pragma once

#include "AbstractDecoder.hpp"

#include <cstdint>

namespace LDPCpp {

class MajorityDecoder final : public AbstractDecoder {
private:
    std::vector<std::vector<int>> m_H;
    std::uint32_t m_num_of_iterations;

public:
    explicit MajorityDecoder(std::uint32_t num_of_iterations, std::uint32_t size) noexcept;
    [[nodiscard]] std::vector<int> decode(const std::vector<int>& received) override;
};

} // namespace LDPCpp
