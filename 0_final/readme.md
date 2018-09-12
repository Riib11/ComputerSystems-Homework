# Homework 0: Galaxy Explorers



## Description

Congratulations! you are now the big-shot CTO of Masstronaut, Inc., a hot new startup developing the next massive multiplayer space exploration game, "Galaxy Explorers".

The current prototype is implemented in Python, which turns out to scale poorly to many players. After some profiling, you realize that one of the slowest pieces of code in your game server is the one that updates the location of all of the objects in space, every turn: spaceships, planets, asteroids, space junk, astronauts taking a space walk, you name it. Millions of objects whose coordinates need to be updated based on their velocity, many times per second.

The goal of this exercise is to understand and improve the performance of this critical piece of code. All of the code and other files should be uploaded to Moodle (as a zip file), or github, and no commit should show a date after the due date. You should also include a README.md file with an overview of the code and answers to non-coding questions. 



## Part 1

Code in `update_locations.py`

a) For 2^8 objects, it takes about 10,000 iteration to get a mean stable to the second decimal, and for 2^24 objects it takes about 20 iterations to get a mean stable to the second decimal. So, it seems reasonable that a sort of exponential (base-2) interpolation between these two extremes would yield good results for the mean time values for between 2^8 and 2^24 objects. I verified this method experimentally.

b) Since the program automatically takes the mean of `iters` number of trials, I can just use the resulting number by choosing the judge an entry by its mean time for a number of objects.

c) [all_data.png]



## Part 2

Code in `update_locations_part.c`, when the `DATATYPE` macro is set to `float`. Results reported in [all_data.png].



## Part 3

Code in `update_locations_part.c`, where the `DATATYPE` macro indicates the type of data to test with. Results reported in [all_data.png].



## Part 4

run with `./memusg ./<target>`

I used this tool for measuring the memory usage: https://gist.github.com/netj/526585. It measures in `ps`'s units, which seem to be 2024 bytes per unit. The progam is contained  in `memusg`.

In each run, the program iterated over the full range of object counts. However, note that the c program used many more iterations per run, as specified in `main.c`, than the python program, as specified in `update_locations.py`. 

Peak memory usages
- pyton num: 25856 units
- c float: 1608816 units



## Part 5

You're right that debugging C isn't as painful as debugging Python. C/C++'s got nothing on haskell compiling though.


