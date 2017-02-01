#include "headers/NeuralNetwork.hpp"

Neuron* NeuralNetwork::factory() {
    return NULL;
}

NeuralNetwork::NeuralNetwork() {
    isReady = false;
}

void NeuralNetwork::loadFromFile(string filename) {
    unsigned layer_count;
    bool issetWeight;
    vector<unsigned> layers_neuron_count;
    ifstream file(filename);
    file >> layer_count;
    for (unsigned i=0; i<layer_count; i++) {
        unsigned t;
        file >> t;
        layers_neuron_count.push_back(t);
    }
    file >> issetWeight;
    for (unsigned i=0; i<layer_count && issetWeight; i++) {
        ListNeuronP layer;
        for (unsigned j=0; j<layers_neuron_count[i] && issetWeight; j++) {
            Neuron* neuron = new Neuron();
            neuron->
        }
        layers.push_back(layer);
    }
}

void NeuralNetwork::saveToFile(string) {
    //
}
