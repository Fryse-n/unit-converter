#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include "FileHandler.h"
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

class JSONHandler : public FileHandler {
private:
        nlohmann::json jsonData;

public:
    bool load(std::string filename) override;

    // Selector: JSON key
    std::vector<std::string> getColumn(std::string selector) override ;

    void appendColumn(std::string newHeader, const std::vector<std::string>& values) override;

    void save(std::string filename) override;
};

#endif