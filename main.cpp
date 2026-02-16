#include <iostream>
#include <vector>
#include "Appliance.h"

void addAppliance(std::vector<Appliance>& appliances) {
    std::string name;
    double power, hours;
    std::cout << "Enter appliance name: ";
    std::cin >> name;
    std::cout << "Enter power rating (W): ";
    std::cin >> power;
    std::cout << "Enter daily usage hours: ";
    std::cin >> hours;
    appliances.emplace_back(name, power, hours);
}

void viewAppliances(const std::vector<Appliance>& appliances) {
    std::cout << "Registered Appliances:\n";
    for (const auto& a : appliances) {
        std::cout << "Name: " << a.getName()
                  << ", Power: " << a.getPowerRatingW() << "W"
                  << ", Daily Usage: " << a.getDailyUsageHours() << " hours\n";
    }
}

double calculateTotalEnergy(const std::vector<Appliance>& appliances) {
    double total = 0;
    for (const auto& a : appliances) {
        total += a.calculateEnergyKwh();
    }
    return total;
}

void calculateBill(double energyKwh, double ratePerKwh) 
{
    double bill = energyKwh * ratePerKwh;
    std::cout << "Total Energy: " << energyKwh << " kWh\n";
    std::cout << "Bill: GHC " << bill << "\n";
}

int main() 
{
    std::vector<Appliance> appliances;
    double ratePerKwh = 0.5; // example rate

    while (true) 
    {
        std::cout << "1. Add Appliance\n2. View Appliances\n3. Calculate Bill\n4. Exit\n";
        int choice;
        std::cin >> choice;
        switch (choice) 
        {
            case 1: addAppliance(appliances); break;
            case 2: viewAppliances(appliances); break;
            case 3: calculateBill(calculateTotalEnergy(appliances), ratePerKwh); break;
            case 4: return 0;
            default: std::cout << "Invalid choice\n";
        }
    }
}
