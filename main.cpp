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

int main() {
    std::vector<Appliance> appliances;

    while (true) {
        std::cout << "1. Add Appliance\n2. View Appliances\n3. Exit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: addAppliance(appliances); break;
            case 2: viewAppliances(appliances); break;
            case 3: return 0;
            default: std::cout << "Invalid choice\n";
        }
    }
}
