#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "quiz_item.h"
#include "reader.h"

nlohmann::json Reader::getFileContent() {
    std::ifstream file("quiz.json");
    auto json = nlohmann::json::parse(file);

    return json;
}

std::vector<Quiz> Reader::getParsedObject() {
    auto content = getFileContent();
    std::vector<Quiz> q = content.get<std::vector<Quiz>>();

    return q;
}
