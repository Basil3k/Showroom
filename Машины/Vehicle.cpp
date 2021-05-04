#include <sstream>


#include "Vehicle.h"
#include "Utils.h"

Vehicle::Vehicle(std::string model, std::string color, int priece)
   : m_model(model)
   , m_color(color)
   , m_price(priece)
{
}

Vehicle::Vehicle()
{
   m_model = "";
   m_color = "";
   m_price = 0;
}

Vehicle::Vehicle(std::string vehicle)
{
   StringToVehicle(vehicle);
}

Vehicle::~Vehicle() // not required, should be deleted
{
  for (auto it : vehicle)
  {
     delete it;
  }
}

void Vehicle::StringToVehicle(const std::string& vehicle)
{
   auto splitted_vehicle = Utils::split(vehicle, ' ');
   std::string flag = splitted_vehicle.at(0);
   m_model = splitted_vehicle.at(1);
   m_color = splitted_vehicle.at(2);
   m_price = std::stoi(splitted_vehicle.at(3));
}

Vehicle::Vehicle(const Vehicle& vehicle)
{
   m_model = vehicle.m_model;
   m_color = vehicle.m_color;
   m_price = vehicle.m_price;
}


std::string Vehicle::VehicleToString()
{
   return "" + m_model  + " "
      + m_color + " " +
      std::to_string(m_price);
}

std::string Vehicle::VehicleToDb()
{
   return "" + m_model + " "
      + m_color + " " +
      std::to_string(m_price);
}

bool operator!=(const Vehicle& lhs, const Vehicle& rhs)
{

   return ((lhs.m_color != rhs.m_color)
      or (lhs.m_model != rhs.m_model)
      or (lhs.m_price != rhs.m_price));
}

bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
   return ((lhs.m_color == rhs.m_color)
      or (lhs.m_model == rhs.m_model)
      or (lhs.m_price == rhs.m_price));
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle)
{
   out << vehicle.m_model << std::endl;
   out << vehicle.m_color << std::endl;
   out << vehicle.m_price << std::endl;
   
   return out;
}

std::istream& operator>>(std::istream& in,  Vehicle& vehicle)
{

   vehicle.TakeFromConsole(in);
   return in;
}

std::istream& Vehicle::TakeFromConsole(std::istream& in)
{
   std::cout << "It vehicle" << std::endl;
   in >> m_model;
   in >> m_color;
   in >> m_price;

   return in;
}
