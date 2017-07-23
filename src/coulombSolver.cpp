#include <cmath>
#include <iostream>

#include "coulombSolver.hpp"
#include "mathHelpers.hpp"

#ifdef CALCULATE_POTENTIAL
#define FORCE_SIZE 4
#else
#define FORCE_SIZE 3
#endif

using namespace std;

vector<Float_t> force(const size_t &i,
                      const vector<pair<Float_t, vector<Float_t>>> &particles) {
  vector<Float_t> force(FORCE_SIZE, Float_t(0));
  for (size_t j = 0; j < particles.size(); j++) {
    if (i == j) {
      continue;
    }
    Float_t dist = distance(particles[i].second, particles[j].second);
#ifdef CALCULATE_POTENTIAL
    Float_t potential = particles[j].first / dist;
    force[3] += potential;
#endif
    Float_t prefactor =
        (particles[i].first * particles[j].first) / pow(dist, 3);
    for (size_t k = 0; k < 3; k++) {
      Float_t force_component =
          (prefactor * (particles[i].second[k] - particles[j].second[k]));
      force[k] += force_component;
    }
  }
  return force;
}

Float_t energy(const vector<pair<Float_t, vector<Float_t>>> &particles,
               const vector<vector<Float_t>> &forces) {
  Float_t Energy = 0;
  for (size_t i = 0; i < particles.size(); i++) {
    Energy += particles[i].first * forces[i][3];
  }
  Energy /= 2;
  cout << "Calculated Coulomb Energy to be: " << Energy << endl;
  return Energy;
}

namespace coulombSolver {
vector<vector<Float_t>>
forces(const vector<pair<Float_t, vector<Float_t>>> &particles) {
  vector<vector<Float_t>> forces(particles.size(),
                                 vector<Float_t>(4, Float_t(0)));
  for (size_t i = 0; i < particles.size(); i++) {
    forces[i] = force(i, particles);
  }
#ifdef CALCULATE_POTENTIAL
  energy(particles, forces);
#endif
  return forces;
}
}
