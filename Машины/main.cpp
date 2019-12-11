#include <iostream>

#include "showroom.h"

int main()
{
   Car car_1;
   car_1 = {"Lada", "ler", 5, 7};
   Boat boat_1 {"boat", "white", 100000, 125};
   Car car_2;
   car_2 = { "Lada", "ler", 5, 7 };

   Showroom showroom;
   showroom.AddVehicle(&car_1);
   showroom.AddVehicle(&boat_1);
   showroom.AddVehicle(&car_2);
   showroom.TakeAllVehicleFromDb();
   showroom.PrintAllVehicle();
   showroom.FindVehicle(car_2);
   showroom.SaveAllVehicleToDb();

   return 0;
}
