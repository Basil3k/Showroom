
#include <sstream>

#include "Boat.h"
#include "Utils.h"

Boat::Boat(std::string model, std::string color,
   int priece, size_t stern_long)
   : Vehicle { model, color, priece }
   , m_stern_long{ stern_long }
{}

Boat::Boat()
{
   m_model = "";
   m_color = "";
   m_price = 0;
   m_stern_long = 0;
}

Boat::Boat(const Boat& boat)
{
   m_model = boat.m_model;
   m_color = boat.m_color;
   m_price = boat.m_price;
   m_stern_long = boat.m_stern_long;
}

Boat::Boat(std::string boat)
{
   StringToVehicle(boat);
}

std::string Boat::VehicleToDb()//this method let save vehicle to database vith flag
{                              //flag let define vehicle (it car or boat) when take vehicle from database 
   return "" + m_flag + " " + m_model + " "
      + m_color + " " +
      std::to_string(m_price) + " "
      + std::to_string(m_stern_long);
}

void Boat::StringToVehicle(const std::string& vehicle)//it used when take vehicle from db for parse string to vehicle parameters
{
   auto splitted_vehicle = Utils::split(vehicle, ' ');
   std::string flag = splitted_vehicle.at(0);
   m_model = splitted_vehicle.at(1);
   m_color = splitted_vehicle.at(2);
   m_price = std::stoi(splitted_vehicle.at(3));
   m_stern_long = std::stol(splitted_vehicle.at(4));
}

bool operator!=(const Boat& lhs, const Boat& rhs)
{
   return ((lhs.m_color != rhs.m_color)
      or (lhs.m_model != rhs.m_model)
      or (lhs.m_price != rhs.m_price)
      or (lhs.m_stern_long != rhs.m_stern_long));
}

bool operator==(const Boat& lhs, const Boat& rhs)
{
   return ((lhs.m_color == rhs.m_color)
      or (lhs.m_model == rhs.m_model)
      or (lhs.m_price == rhs.m_price)
      or (lhs.m_stern_long == rhs.m_stern_long));
}

std::ostream& operator<<(std::ostream& out, const Boat& boat)
{
   std::cout << "model is : " << std::endl;
   out << boat.m_model << std::endl;
   std::cout << "color is : " << std::endl;
   out << boat.m_color << std::endl;
   std::cout << "price is : " << std::endl;
   out << boat.m_price << std::endl;
   std::cout << "stern long is : " << std::endl;
   out << boat.m_stern_long << std::endl;

   return out;
}

std::istream& operator>>(std::istream& in, Boat& boat)
{
   in >> boat.m_model;
   in >> boat.m_color;
   in >> boat.m_price;
   in >> boat.m_stern_long;

   return in;
}