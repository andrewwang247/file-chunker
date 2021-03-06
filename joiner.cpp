/*
Join multiple chunks into single file.

Copyright 2021. Siwei Wang.
*/
#include "joiner.h"
#include <fstream>
#include <string>
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

unsigned Joiner::chunk(const std::string& filename) {
  unsigned chunk_idx = 0;
  ofstream ofp(filename);
  while (true) {
    ifstream ifp(chunk_name(filename, chunk_idx));
    if (!ifp) break;
    ++chunk_idx;
    ofp << ifp.rdbuf();
  }
  return chunk_idx;
}

string Joiner::report(const string& filename, unsigned num_chunks) {
  return string("Joined ") + to_string(num_chunks) + " chunks into " +
         filename + ".\n";
}
