#include <stdlib.h>

struct atoi_lazy {
    atoi_lazy(char* s) : s(s) {}
    operator uint32_t() const { return atoi(s); }
    private: char* s;
};

#undef uint32_t
#define uint32_t atoi_lazy
