/*
Abstract base class for chunking files.

Copyright 2021. Siwei Wang.
*/
#include "chunker.h"
#include <iomanip>
#include <sstream>
#include <string>
using std::setfill;
using std::setw;
using std::string;
using std::stringstream;

string chunk_name(const string& filename, unsigned chunk_idx) {
  stringstream ss;
  ss << setw(3) << setfill('0');
  ss << chunk_idx;
  return filename + '_' + ss.str();
}
