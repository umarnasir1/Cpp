#ifndef _MONEY_H
#define _MONEY_H 

#include<iostream>

class Money{
    friend std::ostream &operator<<(std::ostream &os, const Money &rhs);  
private:
    int dollars;
    int cents;
public: 
    Money(int dollars, int cents);
    Money(int total);
};

#endif // _MONEY_H