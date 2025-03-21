#include "MajorityDecoder.hpp"

#include <random>

namespace decoder {

MajorityDecoder::MajorityDecoder(std::uint32_t num_of_iterations) noexcept
    : m_num_of_iterations(num_of_iterations) {}

std::vector<int> MajorityDecoder::decode(const std::vector<int>& received) {
    std::vector<int> decoded;
    std::random_device(rd);
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    for (int bit : received) {
        int votes = 0;
        for (int i = 0; i < m_num_of_iterations; ++i) {
            votes += (bit ^ dist(gen));
        }
        decoded.push_back(votes > m_num_of_iterations / 2 ? 1 : 0);
    }
    return decoded;
}

} // namespace decoder
