//
// Created by danila on 29.10.2021.
//

#include "LieDetector.h"

Cluster &Cluster::operator+=(const Question &cluster_question) {
    m_cluster[m_size] = cluster_question;
    m_size += 1;

    const char* ans = cluster_question.m_answer.get_c();
    if (ans[0] == '1') { m_numTrue += 1; }
    if (ans[0] == '0') { m_numFalse += 1; }
    return *this;
}

Vector Cluster::result() const {
    Vector result;
    double part = double(m_numTrue)/(m_numTrue + m_numFalse);

    if (part >= 0.8) { result.set_C('1'); }
    if (part <= 0.2) { result.set_C('0'); }
    if (part > 0.2 && part < 0.8) { result.set_C('X'); }
    return result;
}