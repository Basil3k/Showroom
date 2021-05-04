#include <fstream>
#include <iostream>

#include "showroom.h"
// uncomment destructor because of we use memory from heap, we should safely return used memory to it
//Showroom::~Showroom() 
//{
//   for (auto it : vehicles)
//   {
//      delete &it;
//   }
//}

void Showroom::AddVehicle(Vehicle* vehicle)
{
   vehicles.push_back(vehicle);
}

void Showroom::SaveAllVehicleToDb()
{
   std::ofstream data_base("AllVehicle.txt"); // move this variable to common.h and make it constant constexpr
   for (auto it : vehicles)
   {
      data_base << it->VehicleToDb() <<"\n";
   }
}

std::string Showroom::FlagFromDb(const std::string& vehicle)//here get only first token from database
{
   auto splitted_vehicle = Utils::split(vehicle, ' ');
   if (splitted_vehicle.size() > 0)//sometimes we have string which have only symbol of strings end '\n'                          
   {                               //we must compare size compared string for avoidance this situation
      std::string flag = splitted_vehicle.at(0);
      return flag; // it could be decreased to "return splitted_vehicle.at(0)"
   }
}

void Showroom::TakeAllVehicleFromDb()
{
   // move this variable to common.h and make it constant constexpr
   std::fstream data_base("AllVehicle.txt", std::ios::in); 
   if (data_base)//need to check whether we opened the database or not
   {
      while (!data_base.eof())
      {
      std::string boat_line; // variable name does not correspond purpose
      std::getline(data_base, boat_line);
      auto flag = FlagFromDb(boat_line);
      // flag count could be to great and write branch for any flag is not good decision
      // also move all flags to common file
      if (flag == "b")
      {
         vehicles.push_back(new Boat(boat_line));
      }
      else if (flag == "c")
      {
         vehicles.push_back(new Car(boat_line));
      }
      }
   } // do somethink in "else" case
}

void Showroom::PrintAllVehicle()
{
   for (auto it : vehicles)
   {
      std::cout << it->VehicleToString() << std::endl;
   }
}

bool Showroom::FindVehicle(Vehicle& vehicle)
{
   //Vehicle* car = new Car;  //it use if need take vehicle (car/boat) from dm
   //std::cin >> *car;
   for (auto it : vehicles)
   {
      if (*it == vehicle) // should be compare car's parameters
      {
         std::cout << "We have vehicle what you find." << std::endl;
         return true;
      }
      else
      {
         std::cout << "We dont have vehicle what you find." << std::endl;
         return false;
      }
   }
}


