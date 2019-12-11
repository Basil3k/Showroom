#include <sstream>

#include "car.h"
#include "Utils.h"

Car::Car(std::string model, std::string color, 
              int priece, int number_of_wheels)
   : Vehicle (model, color, priece)
   ,m_number_of_wheels(number_of_wheels)
{}

Car::Car()
{
   m_model = "";
   m_color = "";
   m_price = 0;
   m_number_of_wheels = 0;
}

Car::Car(const Car& vehicle)
{
   m_model = vehicle.m_model;
   m_color = vehicle.m_color;
   m_price = vehicle.m_price;
   m_number_of_wheels = vehicle.m_number_of_wheels;
}

Car::Car(std::string car)
{
   StringToVehicle(car);
}

void Car::StringToVehicle(const std::string& vehicle)//here string which we get from db parsed on car fields
 {
    auto splitted_vehicle = Utils::split(vehicle, ' ');
    m_model = splitted_vehicle.at(1);
    m_color = splitted_vehicle.at(2);
    m_price = std::stoi(splitted_vehicle.at(3));
    m_number_of_wheels = std::stoi(splitted_vehicle.at(4));
 }

std::string Car::VehicleToDb()//this method let save vehicle to database vith flag
{                             //flag let define vehicle (it car or boat) when take vehicle from database 
   return "" + m_flag + " " + m_model + " "
      + m_color + " " +
      std::to_string(m_price) + " "
      + std::to_string(m_number_of_wheels);  
}

bool operator!=(const Car& lhs, const Car& rhs) 
{

   return ((lhs.m_color != rhs.m_color)
        or (lhs.m_model != rhs.m_model)
        or (lhs.m_price != rhs.m_price)
        or (lhs.m_number_of_wheels != rhs.m_number_of_wheels));
}

bool operator==(const Car& lhs, const Car& rhs)
{
   return ((lhs.m_color == rhs.m_color)
      or (lhs.m_model == rhs.m_model)
      or (lhs.m_price == rhs.m_price)
      or (lhs.m_number_of_wheels == rhs.m_number_of_wheels));
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
   out << car.m_model << std::endl;
   out << car.m_color << std::endl;
   out << car.m_price << std::endl;
   out << car.m_number_of_wheels << std::endl;

   return out;
}

std::istream& operator>>(std::istream& in, Car& car)
{
   car.TakeFromConsole(in);
   return in;
}

std::istream& Car::TakeFromConsole(std::istream& in)
{
   in >> m_model;
   in >> m_color;
   in >> m_price;
   in >> m_number_of_wheels;

   return in;
}