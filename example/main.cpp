#include "Context.hpp"
#include "MajorityDecoder.hpp"
#include "matrix.hpp"

#include <iostream>

using namespace decoder;

int main(int argc, char const *argv[]) {
    std::vector<int> original_message = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for (auto i: original_message) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    std::vector<std::vector<int>> base_matrix = {
        {0, 1, -1},
        {2, -1, 3},
        {-1, 0, 1}
    };

    std::uint32_t block_size = 3;

    std::vector<std::vector<int>> H = create_parity_check_matrix(base_matrix, block_size);

    //for (int i = 0; i < H.size(); ++i) {
    //    for (int j = 0; j < H[0].size(); ++j) {
    //        std::cout << H[i][j] << " ";
    //    }
    //    std::cout << "\n";
    //}
    //std::cout << "\n";

    Channel ch(0.1);
    MajorityDecoder dec(H, 100);
    Context cntx(original_message, &ch, &dec);

    std::vector<int> decoded = cntx.process();

    for (auto i: decoded) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
