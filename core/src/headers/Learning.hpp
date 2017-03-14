#ifndef LEARNING_HPP
#define LEARNING_HPP

#include <cmath>
#include "Neuron.hpp"
#include "NeuralNetwork.hpp"

/**
 * Parent for learning classes
 */
class Learning {
protected:
    double speed;
    unsigned currentIteration;
    unsigned iterationCount;
    NeuralNetwork* network;
    double summaryError;
public:
    /* Get and set speed param */
    double getSpeed();
    void setSpeed(double);
};

#endif
