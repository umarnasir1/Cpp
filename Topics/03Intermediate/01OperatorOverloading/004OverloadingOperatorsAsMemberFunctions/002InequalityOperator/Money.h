#ifndef _MONEY_H_
#define _MONEY_H_

class Money{
    int dollars; 
    int cents; 
public: 
    Money(int dollars, int cents); 
    Money(int total); 

    bool operator== (const Money &rhs) const;
    bool operator!= (const Money &rhs) const;
};

#endif