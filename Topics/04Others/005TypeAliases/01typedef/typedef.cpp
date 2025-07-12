#include <iostream>
#include <cstdint> // defines types uint32_t, uint64_t, etc

typedef uint32_t points_t; // unsigned integer 32 bits; points_t is alias for uint32_t
typedef uint64_t rank_t;

struct score {
    points_t p {};
    rank_t r {};
};

int main() {
    score s { 5, 1 }; // initialization
    std::cout << "score s had " << s.p << " points and a rank of " << s.r << std::endl;
}
