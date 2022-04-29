#ifndef QUIZ_READER_H
#define QUIZ_READER_H

#include <string>
#include <vector>
#include "quiz_item.h"

class Reader {
public:
    static std::vector<Quiz> getParsedObject();

private:
    static nlohmann::json getFileContent();
};

#endif
