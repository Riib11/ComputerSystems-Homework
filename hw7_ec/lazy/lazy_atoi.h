#include <stdlib.h>

// wrapper for a lazily-evluated atoi
struct atoi_lazy {
    atoi_lazy(char* s) : s(s) {}
    // only when uint32_t is needed for checking, THEN run the atoi
    operator uint32_t() const { return atoi(s); }
    private: char* s;
};

// redefine uint32_t so that lazily evalution
// is delayed till needed in `checksum`
#undef uint32_t
#define uint32_t atoi_lazy
