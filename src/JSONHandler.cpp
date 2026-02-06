#include "JsonHandler.h"
#include <fstream>

bool JsonHandler::load(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    file >> jsonData;
    return true;
}

std::vector<std::string> JsonHandler::getColumn(std::string selector) {
    std::vector<std::string> result;

    if (!jsonData["columns"].contains(selector))
        return result;

    for (auto& v : jsonData["columns"][selector]) {
        result.push_back(std::to_string(v.get<double>()));
    }
    return result;
}

void JsonHandler::appendColumn(std::string newHeader,
                              const std::vector<std::string>& values) {
    jsonData["columns"][newHeader] = nlohmann::json::array();

    for (const auto& v : values) {
        jsonData["columns"][newHeader].push_back(std::stod(v));
    }
}

void JsonHandler::save(std::string filename) {
    std::ofstream file(filename);
    file << jsonData.dump(4);
}
