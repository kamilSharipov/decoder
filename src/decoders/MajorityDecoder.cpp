#include "MajorityDecoder.hpp"
#include "matrix.hpp"

#include <algorithm>
#include <cmath>

namespace LDPCpp {

MajorityDecoder::MajorityDecoder(std::uint32_t num_of_iterations, std::uint32_t size) noexcept
    : m_H(create_parity_check_matrix(BASE_MATRIX, size / BASE_MATRIX.size()))
    , m_num_of_iterations(num_of_iterations) {}

std::vector<int> MajorityDecoder::decode(const std::vector<int>& received) {
    std::vector<int> decoded = received;
    
    // === Initialization: γ = (γ1, . . . ,yn), where yi is the weight of column i of the matrix H ===
    std::vector<int> gamma(m_H[0].size(), 0);
    for (std::uint32_t j = 0; j < m_H[0].size(); ++j) {
        for (const auto& row : m_H) {
            gamma[j] += row[j];
        }
    }

    // === Transposing the H matrix ===
    std::vector<std::vector<int>> HT = transpose_matrix(m_H);

    for (std::uint32_t iterator = 0; iterator < m_num_of_iterations; ++iterator) {
        // === Calculate syndrome = b * HT (in the field GF(2)) ===
        std::vector<int> syndrome(HT.size(), 0);

        for (std::uint32_t i = 0; i < HT.size(); ++i) {
            for (std::uint32_t j = 0; j < received.size(); ++j) {
                syndrome[i] ^= (received[j] & HT[i][j]); 
            }
        }

        // === If syndrome = 0, then return received ===
        if (std::all_of(syndrome.begin(), syndrome.end(), [](int x){ return x == 0; })) {
            return received;
        }

        // === Calculate f = syndrome * H (in the ring Z) ===
        std::vector<int> f(m_H[0].size(), 0);
        for (std::uint32_t i = 0; i < m_H[0].size(); ++i) {
            for (std::uint32_t j = 0; j < m_H.size(); ++j) {
                f[i] += syndrome[j] * m_H[j][i];
            }
        }

        // === Invert the bits, where fi > floor(yi / 2) ===
        for (std::uint32_t i = 0; i < m_H[0].size(); ++i) {
            if (f[i] > std::floor(gamma[i] / 2.0)) {
                decoded[i] ^= 1; 
            }
        }
    }

    return decoded;
}

} // namespace LDPCpp
