#include <cmath>

#include "mathHelpers.hpp"

using namespace std;
Float_t distance(const std::vector<Float_t> &pos1,
                 const std::vector<Float_t> &pos2) {
  Float_t result = 0;
  result = pow(pos1[0] - pos2[0], 2) + pow(pos1[1] - pos2[1], 2) +
           pow(pos1[2] - pos2[2], 2);
  return sqrt(result);
}
