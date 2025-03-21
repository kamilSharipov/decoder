#pragma once

#include <vector>
#include <cstdint>

namespace LDPCpp {

std::vector<std::vector<int>> transpose_matrix(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> create_circulant_matrix(std::uint32_t size, std::uint32_t shift);
std::vector<std::vector<int>> create_parity_check_matrix(const std::vector<std::vector<int>>& base_matrix, std::uint32_t block_size);

} // namespace LDPCpp
