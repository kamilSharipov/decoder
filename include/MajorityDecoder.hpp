#pragma once

#include "AbstractDecoder.hpp"

#include <cstdint>
#include <exception>

namespace decoder {

class MajorityDecoder final : public AbstractDecoder {
private:
    std::uint32_t m_num_of_iterations;

public:
    explicit MajorityDecoder(
        std::vector<std::vector<int>>& H
        , std::uint32_t num_of_iterations) noexcept;
    std::vector<int> decode(const std::vector<int>& received) override;
};

} // namespace decoder
