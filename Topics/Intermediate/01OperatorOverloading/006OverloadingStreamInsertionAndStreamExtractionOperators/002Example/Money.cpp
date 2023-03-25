#include "Money.h"

Money::Money(int dollars, int cents)
    :dollars{dollars}, cents{cents} {
}

Money::Money(int total)
    :dollars{total/100}, cents{total%100}{
}

std::ostream &operator<<(std::ostream &os, const Money &rhs){
    os << "dollars: " << rhs.dollars
       << " cents: " << rhs.cents; 
    return os; 
}