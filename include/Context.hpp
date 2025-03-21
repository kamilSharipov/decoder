#pragma once

#include "Encoder.hpp"
#include "Channel.hpp"
#include "MajorityDecoder.hpp"

#include <vector>

namespace decoder {

class Context {
private:
    std::vector<int> m_original_message;
    Encoder* m_encoder;
    Channel* m_channel;
    AbstractDecoder* m_abstarct_decoder;

public:
    explicit Context(
        std::vector<int> original_message
        , Encoder* encoder
        , Channel* channel
        , AbstractDecoder* abstract_decoder) noexcept;

};

} // namespace decoder
