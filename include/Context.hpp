#pragma once

#include "Channel.hpp"
#include "AbstractDecoder.hpp"

#include <vector>

namespace LDPCpp {

class Context {
private:
    std::vector<int> m_original_message;
    Channel* m_channel;
    AbstractDecoder* m_decoder;

public:
    explicit Context(
        std::vector<int> original_message
        , Channel* channel
        , AbstractDecoder* decoder) noexcept;

    std::vector<int> process();
};

} // namespace LDPCpp
