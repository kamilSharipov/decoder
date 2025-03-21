#include "Encoder.hpp"
#include "Channel.hpp"
#include "MajorityDecoder.hpp"

#include <iostream>

using namespace decoder;

int main(int argc, char const *argv[]) {
    std::vector<int> original_message = {0, 1, 0, 1, 1, 0, 1, 0};

    for (auto i: original_message) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    Encoder encoder(4);
    
    std::vector<int> encoded = encoder.encode(original_message);

    Channel channel(0.1);

    std::vector<int> received = channel.transmit(encoded);

    MajorityDecoder majority_decoder(10000);

    std::vector<int> vec = majority_decoder.decode(original_message);

    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
