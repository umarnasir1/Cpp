#ifndef _MONEY_H
#define _MONEY_H

#include<iostream>

class Money{
    friend Money operator+(const Money &lhs, const Money &rhs); 
private:
    int dollars; 
    int cents; 
public:
    Money(int dollars, int cents);
    Money(int total);
    int get_dollars() const {return dollars;}
    int get_cents() const {return cents; }
};

#endif