#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include "Neuron.hpp"

/**
 * Random number between A and B
 * @param  A Number
 * @param  B Number
 * @return   Result
 */
#define rangerand(A,B) (static_cast <double> (rand()) % B + A)
/**
 * Random number between 0 and 1
 * @return Result
 */
#define randone() ((double) rand() / (RAND_MAX))

typedef std::vector<Neuron*> ListNeuronP;
typedef std::vector<ListNeuronP> ListLayer;

using namespace std;

class NeuralNetwork {
private:
    /* Layers array */
    ListLayer layers;
    bool isReady;
public:
    /* Default constructor */
    NeuralNetwork();

    /**
     * Load schema and weights from text file
     * @param string File name
     * @param bool   Load schema only (default: false)
     */
    void loadFromFile(string, bool);

    /**
     * Save schema and weights into text file
     * @param string File name
     */
    void saveToFile(string);

    /**
     * Print NN information
     */
    void print();

    /**
     * Processing NN
     */
    void process();

    /**
     * Set values on input layer
     * @param ListDouble Values
     */
    void setInput(ListDouble);

    /**
     * Get output values
     * @return Values array
     */
    ListDouble getOutput();

    /**
     * Print output values without return
     * @param string Filename (default: stdout)
     */
    void printOutput(string);

    /**
     * Get output pointers from N layer
     * @param  unsigned N
     * @return          Pointer array
     */
    ListDoubleP getOutputPointers(unsigned);

    /**
     * Get N layer
     * @param  unsigned N
     * @return          Pointer array
     */
    ListNeuronP getLayerAt(unsigned);

    /**
     * Get layers count
     * @return Count
     */
    unsigned getLayersCount();

    /**
     * Get derivative from each neurons on N layer
     * @param  unsigned N
     * @return          Derivative array
     */
    ListDouble getDerivativesLayer(unsigned);
};

#endif
