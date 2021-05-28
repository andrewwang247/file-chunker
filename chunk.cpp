/*
Driver program to run chunking operations.

Copyright 2021. Siwei Wang.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "chunker.h"
#include "joiner.h"
#include "splitter.h"
using std::any_of;
using std::cout;
using std::invalid_argument;
using std::ios_base;
using std::isdigit;
using std::make_unique;
using std::stoul;
using std::string;
using std::unique_ptr;

/**
 * Parses arg to determine user operation choice.
 * @param arg User provided argument.
 * @returns True for split, false for join.
 * @throws If arg is invalid.
 */
bool user_chose_split(const char* arg);

/**
 * Parses arg to determine user chunk size choice.
 * @param arg User provided argument.
 * @returns Chunk size.
 * @throws If arg is invalid.
 */
uint64_t user_chunk_sz(const char* arg);

/**
 * Factory to produce chunker objects.
 * @param is_split True for split, false for join.
 * @param chunk_sz Chunk size.
 * @returns A Chunker object.
 */
unique_ptr<Chunker> chunker_factory(bool is_split, uint64_t chunk_sz);

/**
 * Driver program to run chunking operations.
 */
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  if (argc == 1) {
    cout << "Usage: " << argv[0] << " (to see this message)\n";
    cout << "Usage: " << argv[0] << " {filename} --join\n";
    cout << "Usage: " << argv[0] << " {filename} --split\n";
    cout << "Usage: " << argv[0] << " {filename} --split {chunk_size}\n";
    return 0;
  }
  if (argc != 3 && argc != 4) {
    throw invalid_argument(
        "Chunker takes 2 (required) or 3 (optional) arguments.");
  }
  const string filename(argv[1]);
  const auto is_split = user_chose_split(argv[2]);
  const auto chunk_sz =
      (is_split && argc == 4) ? user_chunk_sz(argv[3]) : 100000000;
  auto chunker = chunker_factory(is_split, chunk_sz);
  const auto num_chunks = chunker->chunk(filename);
  if (is_split) {
    cout << "Split " << filename << " into " << num_chunks << " chunks.\n";
  } else {
    cout << "Joined " << num_chunks << " chunks into " << filename << ".\n";
  }
}

bool user_chose_split(const char* arg) {
  const string str_arg(arg);
  if (str_arg == "--split")
    return true;
  else if (str_arg == "--join")
    return false;
  else
    throw invalid_argument("Operation must be \"--split\" or \"--join\".");
}

uint64_t user_chunk_sz(const char* arg) {
  const string str_arg(arg);
  const auto not_digit = [](char ch) {
    return !isdigit(static_cast<unsigned char>(ch));
  };
  if (any_of(str_arg.begin(), str_arg.end(), not_digit)) {
    throw invalid_argument("Chunk size argument must be a positive integer.");
  }
  if (str_arg.size() > 18) {
    throw invalid_argument("Chunk size argument is too large.");
  }
  return stoul(str_arg);
}

unique_ptr<Chunker> chunker_factory(bool is_split, uint64_t chunk_sz) {
  if (is_split) {
    return make_unique<Splitter>(chunk_sz);
  } else {
    return make_unique<Joiner>();
  }
}
