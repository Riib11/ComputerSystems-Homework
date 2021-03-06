# Homework 6: Crank it Up!

_Partners_: Henry Blanchette and Henry Blanchette

## Introduction

For the experiments in this homework, I've changed the way that latency and throughput are measured. I basically had to scrap the client-side implementation of Cache because it didn't handle sending and timing parallel batches of requests. So, I've implemented just enough functionality for this homework's experiments in `experiments_threaded.cpp`.

To throttle the `request_rate`, there is a delay between the sending of asynchronous requests from the client to the server. Then the total delay time is subtracted from the calculated total latency (which is then averaged over the requests).

For all the experiments, the batch load is
- 70% `GET` (90% hit, 10% miss)
- 30% `SET`
- `key_size` = 8 bytes
- `value_size` = 16 bytes


## Previous Performance

This is the same implementation that I had before in hw5.

I used the `perf stat` tool to measure the CPU and other usage statistics of running the experiment. This is what that looked like:

```
Performance counter stats for './hw6':

            154.56 msec task-clock:u              #    0.573 CPUs utilized          
                 0      context-switches:u        #    0.000 K/sec                  
                 0      cpu-migrations:u          #    0.000 K/sec                  
               966      page-faults:u             # 6272.727 M/sec                  
         258608119      cycles:u                  # 1679273.500 GHz                 
         393638534      stalled-cycles-frontend:u #  152.21% frontend cycles idle   
         107615409      instructions:u            #    0.42  insn per cycle         
                                                  #    3.66  stalled cycles per insn
          22330009      branches:u                # 145000058.442 M/sec             
            874998      branch-misses:u           #    3.92% of all branches        

       0.269822853 seconds time elapsed

       0.072897000 seconds user
       0.088022000 seconds sys

```

## Optimized Performance

To optimize performance, I added threads. Pistache has a built-in implementation of multi-threading server and client support, so I took advantage of that.

```
Performance counter stats for './hw6':

        138.90 msec task-clock                #    0.561 CPUs utilized          
          2841      context-switches          # 20586.957 M/sec                 
           461      cpu-migrations            # 3340.580 M/sec                  
           959      page-faults               # 6949.275 M/sec                  
     344712229      cycles                    # 2497914.703 GHz                   (36.51%)
     260837642      stalled-cycles-frontend   #   75.67% frontend cycles idle     (48.10%)
     171670360      instructions              #    0.50  insn per cycle         
                                              #    1.52  stalled cycles per insn  (62.94%)
      34935737      branches                  # 253157514.493 M/sec               (62.65%)
       1315282      branch-misses             #    3.76% of all branches          (59.36%)
      43154569      L1-dcache-loads           # 312714268.116 M/sec               (34.42%)
       3249509      L1-dcache-load-misses     #    7.53% of all L1-dcache hits    (34.26%)
       1796543      LLC-loads                 # 13018427.536 M/sec                (24.94%)
<not supported>      LLC-load-misses                                             

   0.247378626 seconds time elapsed

   0.078966000 seconds user
   0.071229000 seconds sys

```
