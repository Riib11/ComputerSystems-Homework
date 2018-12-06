# Homework 6: Crank it Up!

_Partners_: Henry Blanchette and Henry Blanchette
_Date_: December TODOst, 2018

## Introduction

For the experiments in this homework, I've changed the way that latency and throughput are measured. I basically had to scrap the client-side implementation of Cache because it didn't handle sending and timing parallel batches of requests. So, I've implemented just enough functionality for this homework's experiments in `experiments_threaded.cpp`.

To throttle the `request_rate`, there is a delay between the sending of asynchronous requests from the client to the server. Then the total delay time is subtracted from the calculated total latency (which is then averaged over the requests).

For all the experiments, the batch load is
- 70% `GET` (of which 90% hit, 10% miss)
- 30% `SET`
- `key_size` = 8 bytes
- `value_size` = 16 bytes



## Previous Performance

This is the same implementation that I had before in hw5, except without the Cache class abstraction.

<!-- TODO: how much time is spent on each operation -->
<!-- TODO: measurements -->

## Optimized Performance

Added threads.

<!-- TODO: how much time is spent on each operation -->
<!-- TODO: measurements -->
