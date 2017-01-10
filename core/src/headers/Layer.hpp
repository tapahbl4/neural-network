#ifndef LAYER_HPP
#define LAYER_HPP

#include "Neuron.hpp"

class Layer {
private:

public:
    vector<Neuron*> neurons;
    Layer();
    //Layer(int);
    void addNeuron(Neuron* neuron);
    void process();
    vector<double> getOutput();
};

#endif
