#include <iostream>
#include <vector>
#include "quiz_item.h"
#include "quiz_manager.h"

int points = 0;

void QuizManager::printBreakLine() {
    std::cout << "-----------------------------------" << std::endl;
}

void QuizManager::printQuestion(const Quiz &q) {
    printBreakLine();
    std::cout << q.question << std::endl;
    printBreakLine();

    std::cout << "a) " << q.a << std::endl;
    std::cout << "b) " << q.b << std::endl;
    std::cout << "c) " << q.c << std::endl;
    std::cout << "d) " << q.d << std::endl;
}

std::string QuizManager::getUserInput() {
    std::string answer;
    std::cin >> answer;

    return answer;
}

void QuizManager::clearConsole() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void QuizManager::checkAnswer(const std::string &answer, const Quiz &q) {
    if (answer == q.correctAnswer)
        points++;
}

void QuizManager::displayPoints(const std::vector<Quiz> &quizItems) {
    std::cout << "Twoja liczba punktow wynosi " << points << "/" << quizItems.size();
}

void QuizManager::startQuiz(const std::vector<Quiz> &quizItems) {
    clearConsole();
    for (const auto &item: quizItems) {
        printQuestion(item);
        auto answer = getUserInput();
        checkAnswer(answer, item);
        clearConsole();
    }

    displayPoints(quizItems);
}

