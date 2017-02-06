#ifndef LEARNINGBACKPROPAGATION_HPP
#define LEARNINGBACKPROPAGATION_HPP

#include <iostream>
#include "Neuron.hpp"
#include "NeuralNetwork.hpp"
#include "Learning.hpp"

class LearningBackPropagation : public Learning {
private:
    ListDouble learnData;
public:
    LearningBackPropagation(NeuralNetwork*, double, ListDouble);
    void start(unsigned, unsigned);
    void iteration(ListDouble, ListDouble);
    void log();
    double test(ListDouble);
};

#endif
