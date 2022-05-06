/*
  Uniform Initialization - initializer list to initialize structure (Modern C++)
*/
#include<iostream>
#include<string>
#include<vector>

struct City{
  std::string name;
  long population;
  double cost;
};

struct Country{
  std::string name;
  std::vector<City> cities;
};

struct Tours{
  std::string name;
  std::vector<Country> countries;
};

int main(){

  Tours tours{
    "Tour Ticket Prices from Miami", {
      {
        "Colombia", {
          {"bogota", 8778000, 400.98}, // city
          { "Cali", 2401000, 424.12 },
          { "Medellin", 2464000, 350.98 },
          { "Cartagena", 972000, 345.34 }
        } // Country - City
      },// Country - Colombia
      {
        "Brazil", {
          {"Rio De janiero", 13500000, 567.45},
          { "Sao Paulo", 11310000, 975.45 },
          { "Salvador", 18234000, 855.99 }
        } // Country -City
      }, // Country - Brazil
      {
        "Chile", {
          { "Valdivia", 260000, 569.12 },
          { "Santiago", 7040000, 520.00 }
        } // Country - City
      }, // Country - Chile
      {
        "Argentina", {
          { "Buenos Aires", 3010000, 723.77 }
        } // Country - City
      } // Country - Argentina
    }// Tours - Country
  }; //Tours

  // Accessing Struct elements
  std::cout << tours.name << std::endl;
  // std::cout << tours.countries.at(0) << std::endl; // Error
  // std::cout << tours.countries.name.at(0) << std::endl; // Error

  return 0;
}
