# Homework 2

## Files

- `test.cpp, test.h`. The unit test for Cache. There are multiple privately-scoped subtests that test different features of Cache for different parts of the homework. To run different subtests, make sure to set the correct options in Cache (hard-coded).
- `cache.cpp, cache.h`. The Cache class. There are several options for using the Cache, including `USING_RESIZING_` and `USING_CUSTOM_EVICTION_` (which are variables in Cache::Impl), which alter how the Cache will work, and correspondingly which variants in the unit test you should use.
- `evictor_fifo.cpp, evictor_fifo.h`. The FIFO Evictor for Cache. Can be used by Cache by setting `USING_CUSTOM_EVICTION_ = true`, setting `using_evictor_object_type = FIFO`.

## [1] First Implementation

For the first implementation (referenced as 'vanilla'), I used an `std::unordered_map<std::string, std::pair<val_type, index_type>>` named `cache` in `Cache::Impl` to store the cache's information in the form of a mapping `Key => (Value, Size)`. I needed to use `std::string` rather than `key_type` because `key_type` is const. This setup was intended to work smoothly with the vanilla eviction policy (evict smallest) by storing the value sizes alongside the values.

Each of the cache methods reference a `Cache::Impl` method that actually completes the operation, providing a private-wrapping hierarchy. Each of these methods work like so:

- `set`. Set the key in `cache` to (value,size) as given. If setting the new value would go over the `maxmem_` limit, then evict entries until there is room. If the key is overwriting a stored entry, subtract the previous value size from `memused_` and add the new value size to `memused_`. Otherwise, just add the new value size to `memused_`.
- `get`. Get the value in the (value,size) pair mapped to by the given key in `cache`.
- `del`. Erase all entries in `cache` that have the given key. For each entry erased, subtract that entry's size from `memused_`.
- `space_used`. Return `memused_`.

## [2] Unit Test

I structured `test.cpp` to handle several variants of the unit test, which are to be called in `unit_test`.

For the first implementation of the Cache, `vanilla_test` tests that
- setting works
- getting works
- space_used is accurate before any eviction
- space_used is accurate after eviction
- deleting works
- space_used is accurate after deletion
- eviction evicts the correct entry: the largest-size entry.

## [3 & 4] Performance and Hash Table

I already used a hash-table (`std::unordered_map`) for my vanilla implementation. I included 

## [5] Dynamic Resizing

My vanilla implementation makes this easy. Rather than evict an entry in `Impl::check_eviction`, I double `maxmem_` until the new entry fits.

## [6] FIFO Eviction

In `evictor_fifo.cpp, evictor_fifo.h`, I constructed a first-in-first-out evictor for Cache by using a queue-like structure. The evictor implements the following methods, in a generic way so that any evictor could take it's place:

- `push`. Adds 
- `evict_next`.
- `del`.
- `visit`.

## Conclusions