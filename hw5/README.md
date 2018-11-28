# Homework 5: Benchmarking the Cache

_Partners_: Henry Blanchette and Henry Blanchette
<!-- _Date_: TODO -->


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
- Recieve response packets to client which specify a response to the execution of the actions the client specified. If a response packet is not recieved within 2 seconds (after sending a request), then throw exception.
- Maintain a single Cache instance.
- Send `new`, `shutdown`, `set`, `get`, `memused`, and `del` action requests to the server, and then return the appropriate values after executing.

## 3. Select Metrics

<!-- You may choose and justify any metric you like, but you must at least include the following metric: sustained throughput, defined as the maximum offered load (in requests per second) at which the mean response time remains under 1 millisecond. For reference and inspiration, check out this paper, especially section V. -->
<!-- Tip: This metric measures the capacity of a system. Ensure that the system whose capacity your actually measuring (the bottleneck) is your cache, not the network or the client host. I suggest you consider running the benchmarking client on a different host on the same physical network, and verify both are unloaded prior to measuring performance. -->

*Sustained Throughput* (capacity): The maximum offer load (requests per second) at which the mean response time remains under 1 millisecond. _Response time_ is defined as the time between the client's sending of a request to the client's recieving of a response.

<!-- TODO: other metrics -->
**


## 4. Parameters

- Cache Key and Value sizes (bytes)
- Cache's max memory (bytes)
- Request rate (requests per second)
- Eviction rate (average evictions yielded per request)
- Set, Get, and Delete rates (average per request)
- Set-Old rate (average number of Sets which set previously-set values, per request)
- Set-new rate (average number of Sets which set not-previously-set values, per request)


## 5. Studied Factors

<!-- TODO: Do tests to see if these numbers are reasonable -->

| Parameter                  | Levels                       |
|----------------------------|------------------------------|
| Request rate               | 16, 64, 128, 256             |
| Set, Get, and Delete rates | 0.00, 0.25, 0.50, 0.75, 1.00 |
| Eviction rate              | 0.00, 0.25, 0.50, 0.75, 1.00 |

## 6. Evaluation Technique

I test the previous factors via measuring a real system - in particular, a _MacBook Pro 2013_ (MacOS Mojave) as server and _Dell Latitude E6430_ (Arch Linux) as client.

## 7. Workload

<!-- Your goal is to try to represent the ETC workload from the memcache workload analysis paper. You may choose and justify any distributions you like for parameters such as request rate, read/write ratio, key size, value size, etc. Choosing too-simple distributions, such as uniform, will likely not be representative enough. On the other hand, there is no need to reproduce the precise distributions reported in the paper (such as GEV), which is complicated and over-fitting. But to the extent you do want to improve your distributions, you can find inspiration in this project. -->

For each experiment I use a workload with
- <!-- TODO: 1024 --> as Cache max memory size
- <!-- TODO: defined in Cache --> as the Cache Key size
- <!-- TODO: 2 --> as the Cache Value size
- <!-- TODO: 512 --> as total number of client requests

Each set of requests is differenciated by
- Offer rate
- Distibution of Set-Old, Set-New, Get, and Delete actions
- Eviction rate


## 8. Experiments

Each experiment is executed via the following steps:
1. Set up Cache server (implemented in hw4_server).
2. Generate randomized set of requests data i.e. parameters for to-be-executed Gets, Sets, etc.
3. Send requests to the server according the generated requests data, at the specified offer rate. Continue sending requests until the total number of client requests is sent.
4. While sending requests, measure the relevant metrics (as described  in section 3).


*Experiment 1*:
| Factor         | Value |
|----------------|-------|
| Offer rate     | <!-- TODO --> |
| SO, SN, G, D   | <!-- [TODO] --> |
| Eviction rate  | <!-- TODO --> |

| Metric | Value |
|--------|-------|
| Sustained Throughput | |

## 9. Analysis

<!-- can i work this out to not be a problem? -->
The request rate may not be exact since it takes a little bit of time to actually send the request on the client-side, which is not accounted for in the timing.

## 10. Results