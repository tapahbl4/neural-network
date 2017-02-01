#ifndef LEARNING_HPP
#define LEARNING_HPP

#include "Neuron.hpp"
#include "NeuralNetwork.hpp"

class Learning {
private:
    double speed;
    unsigned iteration;
    NeuralNetwork* network;
public:
    Learning(NeuralNetwork*, double);
    void algorithmBackPropagation(ListDoubleP, double, unsigned);
    void testBackPropagation();
};

#endif
