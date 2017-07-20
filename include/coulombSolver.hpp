#ifndef COULOMBSOLVER_INCLUDE_COULOMBSOLVER_INCLUDED
#define COULOMBSOLVER_INCLUDE_COULOMBSOLVER_INCLUDED
#include <utility>
#include <vector>

#include "float_t.hpp"

namespace coulombSolver {
std::vector<std::vector<Float_t>>
forces(const std::vector<std::pair<Float_t, std::vector<Float_t>>> &particles);
}
#endif
