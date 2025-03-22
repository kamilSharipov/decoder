#include "Context.hpp"
#include "MajorityDecoder.hpp"
#include "BitFlipDecoder.hpp"
#include "matrix.hpp"

#include <iostream>

using namespace LDPCpp;

const double LOSS_PROBABILITY = 0.1;
const std::uint32_t MAX_NUM_OF_ITERATIONS = 100;

int main() {
    // === Сreating a null message ===
    std::vector<int> original_message = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::vector<int> decoded;

    std::cout << "The original message:\n";
    for (auto i: original_message) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    // === Setting the chanel ===
    Channel ch(LOSS_PROBABILITY);
    
    // === Setting the Majority decoding algorithm ===
    MajorityDecoder maj_dec(MAX_NUM_OF_ITERATIONS, original_message.size());

    // === Creating the Context object and launching the Majority decoding algorithm ===
    Context maj_context(original_message, &ch, &maj_dec);
    decoded = maj_context.process();

    std::cout << "The result of the Majority decoding algorithm:\n";
    for (auto i: decoded) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    // === Setting the BitFlip decoding algorithm ===
    BitFlipDecoder bf_dec(MAX_NUM_OF_ITERATIONS, original_message.size());

    // === Creating the Context object and launching the BitFlip decoding algorithm ===
    Context bf_context(original_message, &ch, &bf_dec);
    decoded = bf_context.process();

    std::cout << "The result of the BitFlip decoding algorithm:\n";
    for (auto i: decoded) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
