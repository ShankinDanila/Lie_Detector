//
// Created by danila on 31.10.2021.
//
#pragma ones
#include "LieDetector.h"
#include "vector"
#include <fstream>
#include <string>
#include <cstdlib>

std::vector<Cluster>input(const std::string& FileQuestions, const std::string& FileAnswers);
void output(std::vector<Cluster> clusters);
