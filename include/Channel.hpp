#pragma once

#include <vector>
#include <random>

namespace LDPCpp {

class Channel final {
private:
    double m_error_probability;

public:
    explicit Channel(double error_probability) noexcept;
    std::vector<int> transmit(const std::vector<int>& data) const;
};

} // namespace LDPCpp
