# File Chunker

Split and join large file to and from smaller chunks. Compile with the provided `Makefile`. Usage options are shown below.

```text
Usage: ./chunk (to see this message)
Usage: ./chunk {filename} --join
Usage: ./chunk {filename} --split
Usage: ./chunk {filename} --split {chunk_size}
```

## Naming Convention

Suppose a file `filename` is split into *N* chunks. The chunks are named `filename_000`, `filename_001`, ..., `filename_{N-1}`, where numbers are written with zero-padding such that they are 3 digits long. Warning: the chunker is not designed to work with more than 1,000 chunks. Doing so is undefined behavior!

## Splitting

The user provides a `filename` that specifies the relative path to a large file. The splitter requires a maximum chunk size parameter to determine the max number of bytes in a chunk. By default, this is 100,000,000 B = 100 MB which matches Github's file size limit. Otherwise, the user can provide an optional `chunk_size` argument.

Note that all chunks except the final one (which may be smaller) will have size exactly equal to the maximum chunk size. Chunks are named using the naming convention as described above.

## Joining

The joiner also requires a `filename` argument. However, it automatically detects chunks based on the naming convention described above. The chunk names must be contiguous in the sense that if there are *N* chunks, then they must be named `filename_000` up to `filename_{N-1}` without skipping any values.
