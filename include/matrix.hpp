#pragma once

#include <vector>
#include <cstdint>

namespace LDPCpp {

const std::vector<std::vector<int>> BASE_MATRIX = {
    {0, 1, -1},
    {2, -1, 3},
    {-1, 0, 1}
};

[[nodiscard]] std::vector<std::vector<int>> transpose_matrix(
    const std::vector<std::vector<int>>& matrix);
    
[[nodiscard]] std::vector<std::vector<int>> create_circulant_matrix(
    std::uint32_t size
    , std::int32_t shift);

[[nodiscard]] std::vector<std::vector<int>> create_parity_check_matrix(
    const std::vector<std::vector<int>>& base_matrix
    , std::uint32_t block_size);

} // namespace LDPCpp
