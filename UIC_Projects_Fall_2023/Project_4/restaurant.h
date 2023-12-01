#include <string>
#define Restaurant_H
using namespace std;

class Restaurant {                    
   public:
    void setAttributes(string restaurantName, string restaurantAddress, string restaurantDate, char restaurantRisk, string restaurantInspection, string restaurantNeighborhood);
    string getName();
    string getAddress();
    string getDate();
    char getRisk();
    string getInspection();
    string getNeighborhood();
    string name;

   private:
    string address;
    string date;
    char risk;
    string inspection;
    string neighborhood;
};

void Restaurant::setAttributes(string restaurantName, string restaurantAddress, string restaurantDate, char restaurantRisk, string restaurantInspection, string restaurantNeighborhood){
    name = restaurantName;
    address = restaurantAddress;
    date = restaurantDate;
    risk = restaurantRisk;
    inspection = restaurantInspection;
    neighborhood = restaurantNeighborhood;
}

string Restaurant::getName(){return name;}
string Restaurant::getAddress(){return address;}
string Restaurant::getDate(){return date;}
char Restaurant::getRisk(){return risk;}
string Restaurant::getInspection(){return inspection;}
string Restaurant::getNeighborhood(){return neighborhood;}






