echo "==> compiling..."
gcc -Wall -Wextra -pedantic update_locations.c -o update_locations
echo "==> running..."
./update_locations
