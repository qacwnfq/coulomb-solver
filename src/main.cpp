#include <chrono>
#include <iostream>

#include "coulombSolver.hpp"
#include "csv.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cerr << endl
         << "Usage: " << argv[0] << " input"
         << " output" << endl
         << endl;
    cerr << "Positional arguments: " << endl;
    cerr << "\t"
         << "input The path to the input file." << endl;
    cerr << "\t"
         << "output The path to the output file." << endl;
    return 1;
  }
  auto particles = csvParse(string(argv[1]));
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  auto forces = coulombSolver::forces(particles);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(t2 - t1).count();
  csvWrite(string(argv[2]), forces);
  cout << "Calculation of " << argv[1] << " took " << duration << "ms." << endl;
  return 0;
}
