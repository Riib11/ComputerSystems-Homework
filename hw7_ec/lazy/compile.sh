: '
g++ -O3 -std=c++17 -march=native       # compiler options
    -Werror -Wall -Wextra -pedantic    # warning options
    driver.cpp converter.cpp           # input files
    -o driver                          # output file (executable)
'

g++ -O3 -std=c++17 -march=native -Werror -Wall -Wextra -pedantic driver.cpp converter.cpp -o driver

