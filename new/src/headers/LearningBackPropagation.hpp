#ifndef LEARNINGBACKPROPAGATION_HPP
#define LEARNINGBACKPROPAGATION_HPP

#include <iostream>
#include "Neuron.hpp"
#include "NeuralNetwork.hpp"
#include "Learning.hpp"

class LearningBackPropagation : public Learning {
private:
    //
public:
    LearningBackPropagation(NeuralNetwork*, double);
    void start(unsigned, unsigned);
    void iteration();
    void log();
};

#endif
