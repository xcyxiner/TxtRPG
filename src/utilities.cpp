#include "utilities.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <openssl/sha.h>
#include <random>
#include <numeric>
#include <math.h>

std::string generate_sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < 8; ++i) {
        ss << std::hex  << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::vector<int> shuffle_options(int count) {
    std::vector<int> order(count);
    std::iota(order.begin(), order.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order.begin(), order.end(), g);
    return order;
}
