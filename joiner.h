/*
Join multiple chunks into single file.

Copyright 2021. Siwei Wang.
*/
#pragma once
#include <string>
#include "chunker.h"

/**
 * Join multiple chunks into single file.
 */
class Joiner : public Chunker {
 public:
  /**
   * Join chunks together.
   * @param filename Name of original file.
   * @returns Number of chunks combined.
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
