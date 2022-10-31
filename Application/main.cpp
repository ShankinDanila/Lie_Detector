//
// Created by danila on 29.10.2021.
//

#include "iostream"
//#include "LieDetector.h"
#include "FileWork.h"

void Dialog() {
    std::string questions;
    std::string answers;
    std::cout << "----This is lie detector test----" << std::endl;
    std::cout << "Please, enter the filename of question file ---> ";
    std::cin >> questions;
    std::cout << "Please, enter the filename of answers file ---> ";
    std::cin >> answers;

    std::vector<Cluster> a;
    a = input(questions, answers);
    output(a);
}

int main(){
    Dialog();
    return 0;
}