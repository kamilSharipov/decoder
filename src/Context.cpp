#include "Context.hpp"

namespace decoder {

Context::Context(
    std::vector<int> original_message
    , Channel* channel
    , AbstractDecoder* decoder) noexcept

    : m_original_message(original_message)
    , m_channel(channel)
    , m_decoder(decoder) {}

std::vector<int> Context::process() {
    std::vector<int> received = m_channel->transmit(m_original_message);
    return m_decoder->decode(received);
}


} // namespace decoder
