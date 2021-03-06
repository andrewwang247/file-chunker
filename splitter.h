/*
Split single file into multiple chunks.

Copyright 2021. Siwei Wang.
*/
#pragma once
#include <string>
#include <vector>
#include "chunker.h"

class Splitter : public Chunker {
 private:
  // Character buffer.
  std::vector<char> buffer;

 public:
  Splitter() = delete;

  /**
   * Init max chunk size.
   * @param chunk_sz Max size of chunk.
   */
  explicit Splitter(uint64_t chunk_sz);

  /**
   * Split file into chunks.
   * @param filename Name of original file.
   * @returns Number of chunks produced.
   */
  unsigned chunk(const std::string& filename) override;

  /**
   * Reports result of splitting operation.
   * @param filename Name of original file.
   * @param num_chunks Number of chunks in operation.
   * @returns Description of operation result.
   */
  std::string report(const std::string& filename, unsigned num_chunks) override;
};
