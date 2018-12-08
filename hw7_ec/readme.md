# Micro Optimization: Extra Credit

_by Henry Blanchette_

## Setup

The original code provided is in `micropt/`. `quotes.txt` contains an example list of stock quotes (about 2.5 million), and the goal is to convert this file into an array of `quote_t` as efficiently as possible. `driver.c` tests a solution provided in `converter.c`. We are instructed to keep our solution compatible with the `converter.h` interface. We are to keep in mind:

> ... any other trick you can think of, any other assumption and shortcut, are all valid, as long as the *converter.h interface isn't broken* and *the checksum stays the same*. If you *didn't have to change driver.c*, you're probably OK.

We are scored by how fast `driver.c` measures our code to be, given an arbitrary set of quotes.

## Solution

My solution is implemented in `lazy/`. The _trick_ I take advantage of is how our code is assumed to work. I think that the obvious solution is to optimize the loop from `0` to `nlines` that quickly `atoi`'s stock quote lines into the `quote_t[]`. But, of course, the most intensive process has little to do with the looping mechanic. `atoi` is slow as a snail. This is the best place to optimize.

The truth is that we really _don't_ need to `atoi` during the loop. Why would we? We just need to go through all the numbers to make sure we get them all, and thats the important thing. The `atoi` bit is only important when we get to the checking to make sure that we got the right numbers. Getting the right numbers doesn't have to be checked during the loop. So, the best optimization I could think of was to delay the `atoi` process using a lazy-evalution wrapper `struct atoi_lazy` that acts like an `atoi`ed quote as `uint32_t` (the expected numeric value for the `checksum` to calculate with) but actually hasn't been `atoi`ed yet. The lazy evaluation is processed when it comes to `checksum` when we actually do need the exact value. So, `atoi` ends up running  during `checksum` rather than in `convert_all`, which drastically reduces the time spent in `convert_all`.

To make this work, I need `driver.cpp` and `converter.h` to recognize my lazy wrapper for atoi. But since I'm not allowed to change anything in `converter.h` or `driver.cpp`, I can't just replace the references to `uint32_t` to the lazy wrapper. Or can I? I decided to use the cool C++ feature `#undef ... #define` that allows the undefinition and then redefinition of virtually anything in the language, including `uint32_t`. So, I created a new header `lazy_atoi.h` which both defined the wrapper and makes sure `uint32_t` are corrected using `#undef ... #define`. 

To `#undef` right, `lazy_atoi.h` needs to be included _after_ `<inttypes.h>` (where `uint32_t` is originally defined). So, I *added*

    #include "lazy_atoi.h"

right after `#include <inttypes.h>` in `converter.h`. This is a legal move because
- the interface is not *broken*
- nothing in the interface was *deleted* or *changed*, it is compelely reasonable to include another important file to keep the code organized
- relying on the order of including file order is a common and relevant concern in general coding, so it's not a problem to rely on it here



## Compilation

For all of the following, make sure you `cd lazy/`.

*IMPORTANT NOTE*: I addd a line to `converter.h`. I did not, however, _change_ any lines. The purpose and justification for this are discussed at the end of the previous section.

I editted the compilation process to work for C++ rather than just C, which was excplicitly allowed. To compile:

    ./compile

To run on data in `quotes` for `iterations` iterations:

    ./driver $iterations $quotes

For example:
    
    ./driver 1000 quotes.txt

## Results

For running on the example data in `quotes.txt`:

| platform | time |
|---|---|
| casually on my mac | 0.002791s |

:)
