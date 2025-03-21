#pragma once

#include <cstdint>
#include <vector>

namespace decoder {

class Encoder final {
private:
    uint32_t m_repetition_factor;

public:
    explicit Encoder(std::uint32_t repetition_factor) noexcept;
    std::vector<int> encode(const std::vector<int>& original) const;
};

} // namespace decoder
