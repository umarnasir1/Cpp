#include<iostream>
#include "Money.h"

Money::Money(int dollars, int cents) 
    :dollars{dollars}, cents{cents} {
}

Money::Money(int total) 
    :dollars {total/100}, cents{total%100} {
}

bool Money::operator== (const Money &rhs) const{
    return ( dollars == rhs.dollars && cents == rhs.cents );
}

bool Money::operator!= (const Money &rhs) const{
    return !(rhs == *this); // using == operator defined in line 12 in this method. Is it because you declared == operator overloading before
}

/*
    we can use     return ( dollars != rhs.dollars && cents != rhs.cents ) but better approach is return !(rhs == *this)

    since we already implemented operator== and it returns a boolean indicating if the objects are the 'same' or not.
    Then we can simple negate that result for !=
    !(rhs == *this)
    become ! (rhs.operator==(*this))
    which compare the two objects rhs and *this using operator== and then negates the result.
*/
