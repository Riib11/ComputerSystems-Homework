#include <cstdlib>
#include <vector>
#include <memory>

using key_type = const std::string;  // Keys for K-V pairs
using val_type = const void*;        // Values for K-V pairs
using index_type = uint32_t;         // Internal indexing to K-V elements

class FIFO {
    
    std::vector<std::string> stack;
    
public:
    
    FIFO() {
        
    };
    
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    auto fifo = new FIFO();

    return 0;
}

