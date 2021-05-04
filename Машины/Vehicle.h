`#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>


class Vehicle
{

public:
   virtual std::string VehicleToString();
   virtual std::string VehicleToDb();
   Vehicle(std::string model, std::string color, int priece);
   Vehicle();
   Vehicle(const Vehicle& vehicle);
   Vehicle(std::string vehicle);
   ~Vehicle();
protected:

   virtual std::istream& TakeFromConsole(std::istream& in);
   virtual void StringToVehicle(const std::string& vehicle);

   friend bool operator!=(const Vehicle& lhs, const Vehicle& rhs);
   friend bool operator==(const Vehicle& lhs, const Vehicle& rhs);
   friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);
   friend std::istream& operator>>(std::istream& in, Vehicle& vehicle);
protected:
    std::list<Vehicle*> vehicle; // not used, should be deleted
    std::string m_model;
    std::string m_color;
         size_t m_price;
};
