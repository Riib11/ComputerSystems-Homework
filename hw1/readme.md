# Homework 1

## Part 1: Benchmarking

`part1.cpp` contains the code that benchmarks the latency for accessing entries in buffer memory of varying sizes. The process works by allocating a buffer (std::vector) with `n` entries, where each entry is a `bufferunit` in size. The total size of the buffer ranges from 2^10 to 2^31. Then, each entry in the buffer is given a unique value in the range 0 to `n`-1 which represents the index of another entry in the buffer.

Then, `TRIALS` number of times, the program accesses the buffer at `index`, and then sets `index` to the value of `buffer[index]`. The goal of this arrangement is to create a cycle of accesses that are in a random order that spans most of the buffer. The pre-fetcher will not be able to predict which entry to access next, so it effectively is only accessing memory in the L1, L2, and main memory without any optimization tricks.

## Part 2: Graphing

`plot/part2.png` depicts a graph of the data my program outputs.

## Part 3: Analysis

1. From 2^0 to 2^10 Kb, the buffer seems to perform relatively consistently at around 3-10 ns, so I think that this range reaches only the L1 cache memory. At between 2^10 and 2^11 Kb, there begins a sharp incline that seems to logarithmically drop off until between 2^19 and 2^20 KB. This range seems to stretch through L2 cache memory, since it is still very quick as compared to what I would expect from main memory access. Finally, starting between 2^19 and 2^20 KB, the latency shoots up again, and this seems to signal a reach into main memory access.

The graph is indeed monotonous, but is not exactly a step function. There are clearly continuity breaks that I infer as signals of seperation of memory layers, but the step seems to engage exponentially and then logarithmically curve off in the one land-locked step which is the L2 cache memory region. I think this is because most of the memory that needs to be accessed is still in L1 memory, so only the bits that drop out into L2 memory cause the slow down. As the buffer gets larger, less of the memory being accessed is in L1, so the latency asymptotically approaches the average L2 latency of about 90 ns it seems. I cannot support this projection for the step from L2 to main memory, but it seems very likely given how its trajectory has started very similarly to L2's.

2. 
