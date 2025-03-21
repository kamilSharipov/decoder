#include "matrix.hpp"

namespace decoder {

std::vector<std::vector<int>> transpose_matrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

std::vector<std::vector<int>> create_circulant_matrix(std::uint32_t size, std::uint32_t shift) {
    std::vector<std::vector<int>> circulant_matrix(size, std::vector<int>(size, 0));

    if (shift == -1) {
        return circulant_matrix;
    }

    for (size_t i = 0; i < size; ++i) {
        circulant_matrix[i][(i + shift) % size] = 1;
    }
    
    return circulant_matrix;
}

std::vector<std::vector<int>> create_parity_check_matrix(
    const std::vector<std::vector<int>>& base_matrix
    , std::uint32_t block_size) {
    std::vector<std::vector<int>> H;

    std::uint32_t rows = base_matrix.size();
    std::uint32_t cols = base_matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        std::vector<std::vector<int>> rowBlocks;
        for (int j = 0; j < cols; ++j) {
            auto block = create_circulant_matrix(block_size, base_matrix[i][j]);
            if (j == 0) {
                rowBlocks = block;
            } else {
                for (int k = 0; k < block_size; ++k) {
                    rowBlocks[k].insert(rowBlocks[k].end(), block[k].begin(), block[k].end());
                }
            }
        }
        H.insert(H.end(), rowBlocks.begin(), rowBlocks.end());
    }

    return H;
}

} // namespace decoder
