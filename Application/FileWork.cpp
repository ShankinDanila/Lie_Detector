//
// Created by danila on 31.10.2021.
//
#include "FileWork.h"

std::vector<Cluster> input(const std::string& FileQuestions, const std::string& FileAnswers) {
    std::vector<Cluster> clusters(NUM_CLUSTERS);

    std::ifstream questions(FileQuestions);
    std::ifstream answers(FileAnswers);

    if (!questions) {
        std::cerr << "Oops, file " << FileQuestions << " couldn't be opened for reading!" << std::endl;
        exit(1);
    }
    if (!answers) {
        std::cerr << "Oops, file " << FileAnswers << " couldn't be opened for reading!" << std::endl;
        exit(1);
    }

    int NUM_QUESTIONS;
    questions >> NUM_QUESTIONS;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        std::string question_str;
        std::getline(questions, question_str, '\n');

        std::string answer_str;
        std::getline(answers, answer_str, '\n');

        Question element(question_str, answer_str);

        clusters[i % OFFSET] += element;
    }
    return clusters;
}

void output(std::vector<Cluster> clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) { std:: cout << clusters[i].result(); }
}
