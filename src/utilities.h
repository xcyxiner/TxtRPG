#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>

std::string generate_sha256(const std::string& str);
std::vector<int> shuffle_options(int count);

#endif // UTILITIES_H

