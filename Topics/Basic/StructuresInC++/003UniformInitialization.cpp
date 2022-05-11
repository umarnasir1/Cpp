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
  std::string title;
  std::vector<Country> countries;
};

int main(){

  Tours tours{
    "Tour Ticket Prices from Miami", {
      {
        "Colombia", {
          {"Bogota", 8778000, 400.98}, // city
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
  std::cout << tours.title << std::endl;
  std::cout << tours.countries.at(0).name << std::endl; // Colombia
  std::cout << tours.countries.at(1).name << std::endl; // Brazil
  std::cout << tours.countries.at(0).cities.at(0).name << std::endl; // Bogota
  std::cout << tours.countries.at(0).cities.at(0).population << std::endl; // 8778000
  std::cout << tours.countries.at(0).cities.at(0).cost << std::endl; // 400.98
  std::cout << tours.countries.at(3).cities.at(0).name << std::endl; // Buenos Aires

  // Displaying all countries
  for (auto country: tours.countries)
    std::cout << country.name << " "; // Colombia Brazil Chile Argentina

  std::cout << std::endl;

  std::cout << tours.countries.size() << std::endl; // 4 - # of countries.
  std::cout << tours.countries.at(1).cities.size() << std::endl; // 3 - #of cities in Brazil


  // Displaying all cities in a country
  for (auto country: tours.countries){
    std::cout << country.name << " : ";
    for (auto city: country.cities)
      std::cout << city.name << " ";
    std::cout << std::endl;
  }

  // Displaying all countries with city names.
  for (Country country: tours.countries)
    for (size_t i{0}; i<country.cities.size(); ++i)
      std::cout << country.name << " - " << country.cities.at(i).name << std::endl;




  std::cout << std::endl;

  return 0;
}
