/*
    Create a data structure for a library catalog card, which includes various elements like the: 
        title, author, publisher, subject, ISBN, WorldCat (OCLC), Dewey Decimal, Year Published, Year Acquired (by the library), Quantity in Stock
    Decide on suitable data types for each element in the structure, such as 
        C-strings for text-based items or anything that should be displayed in a certain format
        integers for numerical items.
        Dewey Decimal format: 510.78 (Two separate numbers each have numerical properties)

    This challenge is designed to help you apply your knowledge of C++ data types in a practical context.
*/
#include<iostream>

struct LibraryCatalogCard{
    const char *title {}; // char title[] {}; character array can also be used  
    const char *author {}; 
    const char *publisher {}; 
    const char *subject {}; 
    const char *isbn {}; 
    const char *oclc {}; // worldcat
    short int ddc1 {}; // broken into two values so we can sort them more easily
    short int ddc2 {}; 
    int YearPublished {}; 
    int YearAcquired {}; 
    int QuantityInStock {};
};

int main (){
    LibraryCatalogCard book1 {
        "The Lost Symbol", "Dan Brown", "Penguin", "Fiction", 
        "9780552149525", "477166381", 510, 78, 2010, 2011, 50
    };

    std::cout << "Title: " << book1.title << std::endl;
    std::cout << "Author: " << book1.author << std::endl;
    std::cout << "Publisher: " << book1.publisher << std::endl;
    std::cout << "Subject: " << book1.subject << std::endl;
    std::cout << "ISBN: " << book1.isbn << std::endl;
    std::cout << "WorldCat (OCLC): " << book1.oclc << std::endl;
    std::cout << "Dewey Decimal: " << book1.ddc1 << "." << book1.ddc2 << std::endl;
    std::cout << "Year Published: " << book1.YearPublished << std::endl;
    std::cout << "Year Acquired: " << book1.YearAcquired << std::endl;
    std::cout << "Quantity in Stock: " << book1.QuantityInStock << std::endl;

    return 0; 
}