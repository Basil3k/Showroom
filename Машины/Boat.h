#pragma once
#include <iostream>

#include "Vehicle.h"

class Boat : public Vehicle
{
   
   public:
   Boat(std::string model, std::string color,
             int priece, size_t m_stern_long);
   Boat();                     
   Boat(const Boat& boat);
   Boat(std::string boat); 

   std::string VehicleToDb() override;
   void StringToVehicle(const std::string& car) override;
   //it overloaded operators
   friend bool operator!=(const Boat& lhs, const Boat& rhs);
   friend bool operator==(const Boat& lhs, const Boat& rhs);
   friend std::ostream& operator<<(std::ostream& out, const Boat& point);
   friend std::istream& operator>>(std::istream& in, Boat& boat);

   private:
   size_t m_stern_long;
   std::string m_flag = {"b"};
};