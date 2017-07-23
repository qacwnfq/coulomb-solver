#include <fstream>
#include <iostream>

#include "csv.hpp"

using namespace std;

vector<pair<Float_t, vector<Float_t>>> csvParse(const string &fileName) {
  vector<pair<Float_t, vector<Float_t>>> result;
  Float_t charge;
  vector<Float_t> pos(3);
  ifstream inputFile(fileName);
  string line;
  getline(inputFile, line);
  getline(inputFile, line);
  while (inputFile >> charge >> pos[0] >> pos[1] >> pos[2]) {
    result.push_back(make_pair(charge, pos));
  }
  inputFile.close();
  return result;
}

int csvWrite(const string &fileName, const vector<vector<Float_t>> &results) {
  if (results.empty()) {
    throw invalid_argument("Received empty results.");
  }
  ofstream outputFile(fileName);
  // figure out how to elegantly write header
  outputFile << "#";
  outputFile.width(13);
  outputFile << right << "Fx";
  outputFile.width(14);
  outputFile << right << "Fy";
  outputFile.width(14);
  outputFile << right << "Fz";
  if (results[0].size() == 4) {
    outputFile.width(14);
    outputFile << right << "Phi";
  }
  outputFile << endl;

  for (const auto &result : results) {
    for (size_t i = 0; i < result.size(); i++) {
      outputFile.width(14);
      outputFile << right << result[i];
    }
    outputFile << endl;
  }
  outputFile.close();
  return 0;
}
