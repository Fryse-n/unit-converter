#ifndef WEIGHT_H
#define WEIGHT_H

#include "Converter.h"

#include <iostream>
#include <string>
#include <map>

class Weight : public Converter {
private:
    std::map<std::string, double> multipliers;

public:
    Weight();

    double toBase(double value, std::string unit) override;

    double fromBase(double baseValue, std::string targetUnit) override;
};

#endif