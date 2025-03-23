#include "Context.hpp"
#include "MajorityDecoder.hpp"
#include "BitFlipDecoder.hpp"

#include <iostream>
#include <fstream>

using namespace LDPCpp;

const int MESSAGE_SIZE = 100;
const int NUM_OF_TRIALS = 100;     
const int MAX_ITERATIONS_RANGE = 20;  
const double ERROR_PROBABILITY = 0.1;
const std::vector<std::string> ALGORITHMS = {"Majority", "BitFlip"};

void simulate() {
    std::vector<int> message(MESSAGE_SIZE, 0);
    std::vector<int> decoded;
    std::ofstream output_file("analysis/results.txt");
    
    output_file << "Iterations\tAlgorithm\tBitErrorRate\n";

    for (int iterations = 1; iterations <= MAX_ITERATIONS_RANGE; ++iterations) {
        Channel ch(ERROR_PROBABILITY);
        for (const std::string& algorithm : ALGORITHMS) {
            int total_errors = 0;
            for (int trial = 0; trial < NUM_OF_TRIALS; ++trial) {
                if (algorithm == "Majority") {
                    MajorityDecoder maj_dec(trial, message.size());
                    Context maj_context(message, &ch, &maj_dec);
                    decoded = maj_context.process();
                } 
                else if (algorithm == "BitFlip") {
                    BitFlipDecoder bf_dec(trial, MESSAGE_SIZE);
                    Context maj_context(message, &ch, &bf_dec);
                    decoded = maj_context.process();
                }

                for (int i = 0; i < MESSAGE_SIZE; ++i) {
                    if (message[i] != decoded[i]) {
                        total_errors++;
                    }
                }

                double bit_error_rate = static_cast<double>(total_errors) / (NUM_OF_TRIALS * MESSAGE_SIZE);
                output_file << iterations << "\t" << algorithm << "\t" << bit_error_rate << "\n";
            }
        }
    }
    double uncoded_bit_error_rate = ERROR_PROBABILITY;
    output_file << "Uncoded\tN/A\t" << uncoded_bit_error_rate << "\n";

    output_file.close();
}

int main() {
    simulate();
    return 0;
}


