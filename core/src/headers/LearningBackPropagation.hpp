#ifndef LEARNINGBACKPROPAGATION_HPP
#define LEARNINGBACKPROPAGATION_HPP

#include <iostream>
#include "Neuron.hpp"
#include "NeuralNetwork.hpp"
#include "Learning.hpp"

/**
 * Back Propagation Algorithm
 */
class LearningBackPropagation : public Learning {
private:
    ListDouble learnData;
    double error;
public:
    /* Default constructor */
    LearningBackPropagation(NeuralNetwork*);

    /**
     * Start learing
     * @param ListDouble Learning data
     * @param double     Speed
     * @param unsigned   Iteration count
     * @param unsigned   Pring information each N iterations (0 for disable)
     */
    void start(ListDouble, double, unsigned, unsigned);

    /**
     * Processing one iteration // TODO: move to private functions
     * @param ListDouble Input data
     * @param ListDouble Teacher data
     */
    void iteration(ListDouble, ListDouble);

    /**
     * Print current information about learning
     */
    void log();

    /**
     * Testing iterations
     * @param  ListDouble Testing data
     * @return            Error in percents
     */
    double test(ListDouble);
};

#endif
