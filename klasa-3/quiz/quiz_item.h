#ifndef QUIZ_H
#define QUIZ_H

#include <nlohmann/json.hpp>

struct Quiz {
    std::string question;
    std::string a;
    std::string b;
    std::string c;
    std::string d;
    std::string correctAnswer;
};

inline void to_json(nlohmann::json &j, const Quiz &q) {
    j = nlohmann::json{
            {"question",      q.question},
            {"a",             q.a},
            {"b",             q.b},
            {"c",             q.c},
            {"d",             q.d},
            {"correctAnswer", q.correctAnswer}
    };
}

inline void from_json(const nlohmann::json &j, Quiz &q) {
    j.at("question").get_to(q.question);
    j.at("a").get_to(q.a);
    j.at("b").get_to(q.b);
    j.at("c").get_to(q.c);
    j.at("d").get_to(q.d);
    j.at("correctAnswer").get_to(q.correctAnswer);
}

#endif
