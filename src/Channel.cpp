#include "Channel.hpp"

namespace decoder {

Channel::Channel(double error_probability) noexcept 
    : m_error_probability(error_probability) {}

std::vector<int> Channel::transmit(const std::vector<int>& data) const {
    std::vector<int> received = data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int& bit : received) {
        if (dist(gen) < m_error_probability) {
            bit ^= 1;
        }
    }
    
    return received;
}

} // namespace decoder
