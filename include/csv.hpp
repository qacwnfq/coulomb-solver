#ifndef COULOMBSOLVER_INCLUDE_CSV_HPP_INCLUDED
#define COULOMBSOLVER_INCLUDE_CSV_HPP_INCLUDED
#include <string>
#include <utility>
#include <vector>

#include "float_t.hpp"

std::vector<std::pair<Float_t, std::vector<Float_t>>>
csvParse(const std::string &fileName);
int csvWrite(const std::string &fileName,
             const std::vector<std::vector<Float_t>> &results);
#endif
