/*
Abstract base class for chunking files.

Copyright 2021. Siwei Wang.
*/
#pragma once
#include <string>

class Chunker {
 public:
  /**
   * Perform chunking operation on file.
   * @param filename Name of original file.
   * @returns Number of chunks produced/combined.
   */
  virtual unsigned chunk(const std::string& filename) = 0;

  /**
   * Reports result of chunking operation.
   * @param filename Name of original file.
   * @param num_chunks Number of chunks in operation.
   * @returns Description of operation result.
   */
  virtual std::string report(const std::string& filename,
                             unsigned num_chunks) = 0;
};

/**
 * Produce name of chunk given base and index.
 * @param filename Name of original file.
 * @param chunk_idx Chunk number.
 * @returns Name of chunk.
 */
std::string chunk_name(const std::string& filename, unsigned chunk_idx);
