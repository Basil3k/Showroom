#pragma once

#include <list>


#include "Boat.h"
#include "car.h"
#include "Utils.h"

class Showroom
{
public:

   Showroom() = default;
   //~Showroom();
   void PrintAllVehicle();
   void AddVehicle(Vehicle* car);
   std::string FlagFromDb(const std::string& vehicle);//it method get first symbol from db
   void SaveAllVehicleToDb();
   void TakeAllVehicleFromDb();
   bool FindVehicle(Vehicle& vehicle);//flag let define vehicle (it car or boat) when take vehicle from database 

protected:
   std::list<Vehicle*> vehicles;
};

