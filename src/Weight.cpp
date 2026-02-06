#include "Weight.h"
#include <iostream>

Weight::Weight() {
    // base = Kilograms
    multipliers["kg"] = 1.0;
    multipliers["g"] = 0.001;
    multipliers["cg"] = 0.00001;
    multipliers["mg"] = 0.000001;
    multipliers["lb"] = 0.453592;
    multipliers["ton"] = 1000.0;
    multipliers["oz"] = 0.0283495;
}

double Weight::toBase(double value, std::string unit){
    if (multipliers.count(unit)) {
        return value * multipliers[unit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; 
}

double Weight::fromBase(double baseValue, std::string targetUnit) {
    if (multipliers.count(targetUnit)) {
        return baseValue / multipliers[targetUnit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; // Error
}