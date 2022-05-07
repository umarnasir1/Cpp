/*
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

void ruler(); // Function Prototype

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

  Tours tours{    //Loading Data into the struc - Uniform Initialization - initializer list to initialize structure (Modern C++)
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

  const int total_width {70};
  const int field1_width {20}; // Country
  const int field2_width {20}; // City
  const int field3_width {15}; // Population
  const int field4_width {15}; // Price

  ruler();
  int title_length = tours.title.length(); // 29
  // std::cout << ((total_width - title_length)/2) << std::endl; //20
  // std::cout << std::setw((total_width - title_length)/2) << "ABCD" << std::endl; // 14
  std::cout << std::setw((total_width - title_length)/2) << "" << tours.title << std::endl; // "" - empty string - setw() will apply to empty string and so trours.title will be displayed after that.
  std::cout << std::endl;
  std::cout << std::setw(field1_width) << std::left << "Country"
            << std::setw(field2_width) << std::left << "City"
            << std::setw(field3_width) << std::right << "Population"
            << std::setw(field4_width) << std::right << "Price"
            << std::endl;

  std::cout << std::setw(total_width)
            << std::setfill('-')
            << "" // setw() and setfill() will apply to empty string
            << std::endl; // display total_width dashes

  for(Country country : tours.countries) {
      for (size_t i = 0; i<country.cities.size(); ++i) {
          std::cout << std::setw(field1_width) << std::left <<  ((i == 0) ? country.name : "") // conditional operator
                         << std::setw(field2_width) << std::left << country.cities.at(i).name
                         << std::setw(field3_width) << std::right<< country.cities.at(i).population
                         << std::setw(field4_width) << std::right << country.cities.at(i).cost
                         << std::endl;
      }
  }



  return 0;
}

// Function Description
void ruler() {
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n" << std::endl;
}
