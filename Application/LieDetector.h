//
// Created by danila on 29.10.2021.
//

#pragma ones
#include <utility>
#include "Vector.h"
#include "string"

using namespace Prog3;

const int OFFSET = 5;           // number of questions in one subsequence and this number is equal
const int NUM_CLUSTERS = 5;     // number of clusters

struct Question {
    std::string m_question;
    Vector m_answer;
    Question() = default;
    Question(Question const &) = default;
    Question& operator=(Question const &) = default;
    Question(std::string question, const std::string& answer):
                                        m_question(std::move(question)),
                                        m_answer(answer) {}
};

struct Cluster {
    Question m_cluster[OFFSET];
    int m_size = 0;
    int m_numTrue = 0;
    int m_numFalse = 0;

    Cluster& operator+=(const Question& cluster_question);
    [[nodiscard]] Vector result() const;
};