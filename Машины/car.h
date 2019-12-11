#pragma once

#include <iostream>

#include "Vehicle.h"

class Car : public Vehicle
{
public:
   Car(std::string model, std::string color,
      int priece, int number_of_wheels);
   Car();                    
   Car(const Car& car);
   Car(std::string car); 

   std::string VehicleToDb() override;
   void StringToVehicle(const std::string& vehicle) override;

   friend bool operator!=(const Car &lhs, const Car &rhs);
   friend bool operator==(const Car& lhs, const Car& rhs);
   friend std::ostream& operator<<(std::ostream &out, const Car &point);
   friend std::istream& operator>>(std::istream& in, Car& car);
   std::istream& TakeFromConsole(std::istream& in) override;

   private:
   size_t m_number_of_wheels;
   std::string m_flag = {"c"}; //it flag written in database for compare car
};