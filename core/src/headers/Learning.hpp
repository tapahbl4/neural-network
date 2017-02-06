#ifndef LEARNING_HPP
#define LEARNING_HPP

#include "Neuron.hpp"
#include "NeuralNetwork.hpp"

class Learning {
protected:
    double speed;
    unsigned currentIteration;
    unsigned iterationCount;
    NeuralNetwork* network;
    double summaryError;
public:
    // Learning(NeuralNetwork*, double);
    // void algorithmBackPropagation(ListDoubleP, double, unsigned);
    // void testBackPropagation();
    double getSpeed();
    void setSpeed(double);
};

#endif
