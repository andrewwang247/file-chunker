/*
Split single file into multiple chunks.

Copyright 2021. Siwei Wang.
*/
#include "splitter.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

Splitter::Splitter(uint64_t chunk_sz) : buffer(chunk_sz, '\0') {}

unsigned Splitter::chunk(const string& filename) {
  unsigned chunk_idx = 0;
  for (ifstream ifp(filename);
       ifp.read(buffer.data(), buffer.size()) || ifp.gcount(); ++chunk_idx) {
    ofstream ofp(chunk_name(filename, chunk_idx));
    ofp.write(buffer.data(), ifp.gcount());
  }
  return chunk_idx;
}

string Splitter::report(const string& filename, unsigned num_chunks) {
  return string("Split ") + filename + " into " + to_string(num_chunks) +
         " chunks.\n";
}
