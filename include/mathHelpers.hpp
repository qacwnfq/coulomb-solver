#ifndef COULOUMBSOLVER_INCLUDE_MATHHELPERS_INCLUDED
#define COULOUMBSOLVER_INCLUDE_MATHHELPERS_INCLUDED
#include "float_t.hpp"
#include <vector>

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

Float_t distance(const std::vector<Float_t> &pos1,
                 const std::vector<Float_t> &pos2);

#endif
