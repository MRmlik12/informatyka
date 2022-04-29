#ifndef QUIZ_QUIZ_MANAGER_H
#define QUIZ_QUIZ_MANAGER_H

#include <vector>
#include <string>
#include "quiz_item.h"

class QuizManager {
public:
    static void startQuiz(const std::vector<Quiz> &quizItems);

private:
    static void printBreakLine();

    static void printQuestion(const Quiz &q);

    static std::string getUserInput();

    static void clearConsole();

    static void checkAnswer(const std::string &answer, const Quiz &q);

    static void displayPoints(const std::vector<Quiz> &quizItems);
};


#endif //QUIZ_QUIZ_MANAGER_H
