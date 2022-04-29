#include <iostream>
#include "reader.h"
#include "quiz_manager.h"

int main() {
    auto quizItems = Reader::getParsedObject();
    QuizManager::startQuiz(quizItems);

    std::string key;
    std::cin >> key;

    return 0;
}
