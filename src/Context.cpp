#include "Context.hpp"

namespace decoder {

Context::Context(
    std::vector<int> original_message
    , Encoder* encoder
    , Channel* channel
    , AbstractDecoder* abstract_decoder)

    : m_original_message(original_message)
    , m_encoder(encoder)
    , m_channel(channel)
    , m_abstarct_decoder(abstract_decoder) {}


    
} // namespace decoder
