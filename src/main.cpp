#include "MajorityDecoder.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {
    std::vector<int> original_message = {0, 1, 0, 1, 1, 0, 1, 0};
    decoder::MajorityDecoder majority_decoder(5);

    std::vector<int> vec = majority_decoder.decode(original_message);

    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
