#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>
#include <fstream>
#include "Neuron.hpp"

typedef std::vector<Neuron*> ListNeuronP;
typedef std::vector<ListNeuronP> ListLayer;

using namespace std;

class NeuralNetwork {
private:
    ListLayer layers;
    Neuron* factory();
    bool isReady
public:
    NeuralNetwork();
    void loadFromFile(string);
    void saveToFile(string);
};

#endif
