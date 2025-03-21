#include "Encoder.hpp"

namespace decoder {

Encoder::Encoder(std::uint32_t repetition_factor) noexcept
    : m_repetition_factor(repetition_factor) {}

std::vector<int> Encoder::encode(const std::vector<int>& original) const {
    std::vector<int> encoded;
    for (int bit : original) {
        for (std::uint32_t i = 0; i < m_repetition_factor; ++i) {
            encoded.push_back(bit);
        }
    }
    return encoded;
}

} // namespace decoder