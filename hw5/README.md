# Homework 5: Benchmarking the Cache

_Partners_: Henry Blanchette and Henry Blanchette
_Date_: December 1st, 2018

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

Definition. _Action Latency_ is the time taken for the client to recieve a response from the server via a client-side Cache method call. This time frame includes the following sections (in order):
1. Client generates request (for given parameters)
2. Client sends request to server
3. Server recieves requestserver executes specified action on server-side Cache
4. Server sends response to client
5. Client recieves reponse

Matric. *Average Action Latency (AAL)*: Given a distribution of actions, the _average action latency_ is the average action latency for running all of those actions. The distribution is run ordered by type in this way:
1. Set old
2. Set new
3. Get
4. Delete

Definition. The _Working Average Action Latency (WAAL)_, given a workload and a percentage of the workload `x`, is the AAL as the Cache is `x`-way through the workload.

Matric. *Sustained Throughput (ST)*: The maximum percentage of the workload at which the WAAL is less than or equal to 1 millisecond.


## 4. Parameters

- Cache Key and Value sizes (bytes)
- Cache's max memory (bytes)
- Set, Get, and Delete rates (average number of Actions per request)
- Set Old rate (average number of Set Actions which set previously-set values, per request)
- Set New rate (average number of Set Actions which set not-previously-set values, per request)
- Eviction rate (average evictions yielded per Set Action)


## 5. Studied Factors

<!-- TODO: Do tests to see if these numbers are reasonable -->
<!-- TODO: see if altering the request rate actually has any effect
			or if I can even measure it meaningfully at all -->

Definition. *Scale* is the coefficient used to scale the Cache max memory size and the number of requests (same coefficient for each).

| Parameter                  | Levels                       |
|----------------------------|------------------------------|
| Set, Get, and Delete rates | 0.00, 0.25, 0.50, 0.75, 1.00 |
| Eviction rate              | 0.00, 0.25, 0.50, 0.75, 1.00 |
| Scale                      | 1, 8, 16                     |

I kept the key and value sizes at a constant 1 and 3 bytes respectively.


## 6. Evaluation Technique

I test the previous factors via measuring a real system - in particular, a _MacBook Pro 2013_ (MacOS Mojave) as server and _Dell Latitude E6430_ (Arch Linux) as client.

To measure _Average Action Latency_:
1. Record `start time`
2. Run Cache client through all the generated requests data
3. Record `end time`
4. The average latency is `({end time} - {start time}) / {number of requests i.e. Cache method calls}`

To measure _Sustained Throughput_:
1. Initialize the `WAAL`. initialize an array `WAAL history`.
2. Record `start time`.
3. Run Cache client through all the generated requests data.
4. Every 10 requests run, update the `WAAL` and append the new value the `WAAL history`.
5. Let `max WAAL index` be the last index of the `WAAL history` at which the `WAAL` is less than 1 ms. Then the sustained throughput is `{max WAAL index} * 10 / {number of requests}`.

## 7. Workload

<!-- Your goal is to try to represent the ETC workload from the memcache workload analysis paper. You may choose and justify any distributions you like for parameters such as request rate, read/write ratio, key size, value size, etc. Choosing too-simple distributions, such as uniform, will likely not be representative enough. On the other hand, there is no need to reproduce the precise distributions reported in the paper (such as GEV), which is complicated and over-fitting. But to the extent you do want to improve your distributions, you can find inspiration in this project. -->

For each experiment I use a workload with
- `512 * scale` as Cache max memory size
- `4` as the Cache Key size (to fit up to 4 digit numbers)
- `1` as the Cache Value size
- `1024 * scale` as total number of client requests

Each set of requests is differenciated by
- Distibution of Set-Old, Set-New, Get, and Delete actions
- Eviction rate (completely determined distribution)


## 8. Experiments

Each experiment is executed via the following steps:
1. Set up Cache server (implemented in hw4_server).
2. Generate set of requests data. This set is ordered like so: Set-Old, Set-New, Get, Delete.
3. Send requests to the server according the generated requests data, at the specified offer rate. Continue sending requests until the total number of client requests is sent.
4. While sending requests, measure the relevant metrics (as described  in section 3).

### Experiment 1: Set Old

| Factor         | Value |
|----------------|-------|
| SO, SN, G, D   | 1.00, 0.00, 0.00, 0.00 |
| Eviction rate  | 0.00 |
| Scale          | 1 - 8 - 16 |

| Scale | AAL | ST |
|-------|-----|----|
| 1     | 0.000178668 s | 0.995122 |
| 8     | 0.000263914 s | 0.999634 |
| 16    | 0.000400837 s | 0.999695 |

### Experiment 2: Set New

| Factor         | Value |
|----------------|-------|
| SO, SN, G, D   | 0.00, 1.00, 0.00, 0.00 |
| Eviction rate  | 0.50 |
| Scale          | 1 - 8 - 16 |

| Scale | AAL | ST |
|-------|-----|----|
| 1     | 0.000225877 s | 0.995122 |
| 8     | 0.000423226 s | 0.999634 |
| 16    | 0.000698039 s | 0.999695 |

### Experiment 3: Set New and Get

| Factor         | Value |
|----------------|-------|
| SO, SN, G, D   | 0.00, 0.50, 0.50, 0.00 |
| Eviction rate  | 0.00 |
| Scale          | 1 - 8 - 16 |

| Scale | AAL | ST |
|-------|-----|----|
| 1     | 0.000260605 s | 0.995122 |
| 8     | 0.00028499 s | 0.999634 |
| 16    | 0.000420611 s | 0.999695 |

### Experiment 4: Set New and Delete

| Factor         | Value |
|----------------|-------|
| SO, SN, G, D   | 0.00, 0.50, 0.00, 0.50 |
| Eviction rate  | 0.00 |
| Scale          | 1 - 8 - 16 |

| Scale | AAL | ST |
|-------|-----|----|
| 1     | 0.000215811 s | 0.995122 |
| 8     | 0.000256885 s | 0.999634 |
| 16    | 0.000395336 s | 0.999695 |

### Experiment 5: Set New, Get, and Delete

| Factor         | Value |
|----------------|-------|
| SO, SN, G, D   | 0.00, 0.50, 0.25, 0.25 |
| Eviction rate  | 0.00 |
| Scale          | 1 - 8 - 16 |

| Scale | AAL | ST |
|-------|-----|----|
| 1     | 0.000201646 s | 0.995122 |
| 8     | 0.000536334 s | 0.999634 |
| 16    | 0.000529358 s | 0.999695 |

## 9. Analysis

I noticed that there were times when I needed to rerun an experiment because the numbers were wildly and obviously innacurate. I think that there were times when a specific request was caught up on the network for some reason, probably having to do with other activity on my wifi network.

I tried to make sure that all activity on the wifi-netowork I was using as an intermediary between my computers was relatively unfilled with other activity than the experiment, but I could not manage this perfectly as I share the network with other people. I did all the experiments in the same 30 minute window of time, so if there is a bias in the reported latencies, I think it is likely systematic rather than random.

I made sure to run my experiments with the DEBUG modes off for both the server and the client.

I noticed that almost all of the throughput values are all negligably less than just `1.00`. This implies that all of the workloads were manageable, continuously throughout the workload, under 1 ms per action. I suspected that the _WAAL versus Percent of Workload_ curve would be something like a square root curve, and that the threshold of 1 ms would be reached after some amount of the workload. Looking at the `WAAL history` data a little, it seems like I am right about this. Also, scaling up the Cache basically scaled the curve upwards (on the _WAAL_ axis). It seems, though that the workloads that I tested never pushed any part of the curve higher than the 1 ms threshold. A good test to do next would be to iterate through a couple higher `Scale` values to see where the curve finally starts hitting that threshold.


## 10. Results

Of all the Cache actions I tested (Set Old, Set New, Get, Delete), the data shows that Set New takes the most amount of time as reflected by AAL. It also scaled the most directly with `scale`. Delete also takes a similar amount of time, but it is hard to test them independently because I tested workloads without any previous entries in the Cache (other than "old"), and there needs to be at least one Set New for each Delete action. I also wonder if the fact that Set Old and Get only access the same key ("old") is taking advantage of some implicit cache that makes those actions slightly faster.

All of the workloads that I tested were essencially completely within the threshold for Sustained Throughput. In the future I should test to find the bounds where the workloads finally push my Cache beyond the 1 ms threshold per action.

