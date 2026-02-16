#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <string>

class Appliance {
private:
    std::string name;
    double powerRatingW; // in watts
    double dailyUsageHours;

public:
    Appliance(std::string n, double p, double u);
    double calculateEnergyKwh() const;
    std::string getName() const;
    double getPowerRatingW() const;
    double getDailyUsageHours() const;
};

#endif // APPLIANCE_H
