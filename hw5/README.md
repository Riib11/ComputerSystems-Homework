# Homework 5: Benchmarking the Cache

Partners: Henry Blanchette and Henry Blanchette

## 1. Goals and Definitions

The system consists of one client and one server. Each is an arbitrary machine, and they are usually different machines. The machines communicate using HTTP over a local wifi network.

The goal of this benchmarking test is to measure the speed and capacity of the network Cache program I implemented in homework 4.

## 2. Services and Outcomes

The Server implements the following:
- Recieve packets from the client which specify actions for the server to carry out.
- Send response packets to client which specify a response to the execution of actions the client specified. If client is not found, then throw exception.
- Maintain a single Cache instance.
- Create new Cache instance.
- Shutdown the server.
- Set entries in Cache instance. If there is not enough room to store new entry, then evict entries until there is room. If no amount of eviction would yield enough space, then throw exception.
- Get entries from Cache instance. If the entry key is not found, then respond `NULL`.
- Remove entries from Cache instance. If the entry key, nothing happens and there is no error.
- Evict entries from Cache instance. 
- Get memory used by Cache instance.

The Client implements the following:
- Send packets to server which specify actions for the server to carry out. If server is not found, then throw exception. If the response indicates that the execution was unsuccessful, then throw exception.
- Recieve response packets to client which specify a response to the execution of the actions the client specified. If a response packet is not recieved within a couple seconds (after sending a request), then throw exception.
- Maintain a single Cache instance.
- Send `new`, `shutdown`, `set`, `get`, `memused`, and `del` action requests to the server, and then return the appropriate values after executing.

## 3. Select Metrics

<!-- You may choose and justify any metric you like, but you must at least include the following metric: sustained throughput, defined as the maximum offered load (in requests per second) at which the mean response time remains under 1 millisecond. For reference and inspiration, check out this paper, especially section V. -->
<!-- Tip: This metric measures the capacity of a system. Ensure that the system whose capacity your actually measuring (the bottleneck) is your cache, not the network or the client host. I suggest you consider running the benchmarking client on a different host on the same physical network, and verify both are unloaded prior to measuring performance. -->

## 4. Parameters

## 5. Studied Factors

## 6. Evaluation Technique

## 7. Workload

<!-- Your goal is to try to represent the ETC workload from the memcache workload analysis paper. You may choose and justify any distributions you like for parameters such as request rate, read/write ratio, key size, value size, etc. Choosing too-simple distributions, such as uniform, will likely not be representative enough. On the other hand, there is no need to reproduce the precise distributions reported in the paper (such as GEV), which is complicated and over-fitting. But to the extent you do want to improve your distributions, you can find inspiration in this project. -->

## 8. Experiments

## 9. Analysis

## 10. Results