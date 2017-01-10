#include "headers/Layer.hpp"

Layer::Layer() {
    //this->neurons = new vector<Neuron>();
}

/*Layer::Layer(int count) {
    //this->neurons = new vector<Neuron>(neurons);
    this->neurons = neurons;
}*/

void Layer::addNeuron(Neuron* neuron) {
    this->neurons.push_back(neuron);
}

void Layer::process() {
    for (unsigned i=0; i<neurons.size(); i++) {
        neurons[i]->process();
    }
}

vector<double> Layer::getOutput() {
    vector<double> output;
    for (unsigned i=0; i<neurons.size(); i++) {
        output.push_back(neurons[i]->output);
    }
    return output;
}
