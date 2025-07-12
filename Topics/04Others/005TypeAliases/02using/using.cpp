#include <iostream>
#include <cstdint> // defines types uint32_t, uint64_t, etc

using points_t = uint32_t;
using rank_t = uint64_t;

struct score {
    points_t p {};
    rank_t r {};
};

int main() {
    score s { 5, 1 }; // initialization
    std::cout << "score s had " << s.p << " points and a rank of " << s.r << std::endl;
}
