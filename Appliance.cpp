#include "Appliance.h"

Appliance::Appliance(std::string n, double p, double u) 
    : name(n), powerRatingW(p), dailyUsageHours(u) {}

double Appliance::calculateEnergyKwh() const {
    return (powerRatingW * dailyUsageHours) / 1000.0;
}

std::string Appliance::getName() const { return name; }
double Appliance::getPowerRatingW() const { return powerRatingW; }
double Appliance::getDailyUsageHours() const { return dailyUsageHours; }
