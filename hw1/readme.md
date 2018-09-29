# Homework 1

By: Henry Blanchette


## Part 1: Benchmarking

`part1.cpp` contains the code that benchmarks the latency for accessing entries in buffer memory of varying sizes. The process works by allocating a buffer (std::vector) with `n` entries, where each entry is a `bufferunit` in size. The total size of the buffer ranges from 2^10 to 2^31. Then, each entry in the buffer is given a unique value in the range 0 to `n`-1 which represents the index of another entry in the buffer.

Then, `TRIALS` number of times, the program accesses the buffer at `index`, and then sets `index` to the value of `buffer[index]`. The goal of this arrangement is to create a cycle of accesses that are in a random order that spans most of the buffer. The pre-fetcher will not be able to predict which entry to access next, so it effectively is only accessing memory in the L1, L2, and main memory without any optimization tricks.



## Part 2: Graphing

`plot/part2.png` depicts a graph of the data my program outputs.



## Part 3: Analysis

1. Predictions

From 2^0 to 2^7 Kb, the buffer seems to perform relatively consistently at around 3-5 ns, so I think that this range reaches only the L1 cache memory. From 2^7 to 2^11, the latency trends higher to 7-12 ns, so this seems to be a reach into the L2 cache memory. At between 2^10 and 2^11 Kb, there begins a sharp incline that seems to logarithmically drop off until between 2^19 and 2^20 KB. This range seems to stretch through main memory, as it is much higher than the quicker buffers. Finally, starting between 2^19 and 2^20 KB, the latency shoots up again, and this seems to signal a reach into some deeper memory.

The graph is indeed monotonous, but is not exactly a step function. There are clearly continuity breaks that I infer as signals of seperation of memory layers, but the step seems to engage exponentially and then logarithmically curve off in the very distinct main memory region. I think this is because most of the memory that needs to be accessed is still in L1 and L2 cache memory, so only the bits that drop out into main memory cause the slow down. As the buffer gets larger, less of the memory being accessed is in L1 and L2, so the latency asymptotically approaches the average main memory access latency of about 90-100 ns it seems. The step between L1 and L2 is much less distinct as a step when graphed alongsize the step between L2 and main memory, but the break from consisten 3-4 ns latencies to the high single digits and low double digits gives it away with a closer look.

2. Data Check

Yes, I did get approximately the numbers cited by the "Teach Yourself Programming in 10 Years" post. It corroborates what I expected from my methods, and indicates that my computer is working normally in respect to memory access. I don't know exactly what to label the sharp jump at the large end of my buffer-size range (2^20+ KB), as the post doesn't really list specifics that look reasonable to my case. I think its likely that the way my program is constructed may yield odd memory access methods when the buffer size gets very close to 2^32 bytes, which is the size of the individual entries in the buffer (`__int32_t`).

3. Conclusions

I am running archlinux natively on my machine, so using `cat /sys/devices/system/cpu/cpu0/cache/index0/size` and the same for `index1`, I find that the first cache is 32 KB and the second is 256 KB. I'm not completely sure if I'm accessing these numbers right. They are pretty close to my predictions, although my reasoning led me to predict them to be larger than they are. This makese sense because even when the buffer starts dropping out into a slower memory layer, the change is incremental as the proportion of memory in the slower layer grows, and it was hard to pinpoint the transition exactly. I recognized this in part 1, but apparently did not account for it enough. 
