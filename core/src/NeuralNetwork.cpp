#include "headers/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() {
    isReady = false;
}

void NeuralNetwork::loadFromFile(string filename, bool onlyScheme = false) {
    srand(time(0));
    unsigned layer_count;
    bool issetWeight;
    vector<unsigned> layers_neuron_count;
    ifstream file(filename);
    if (!file.is_open()) return;
    file >> layer_count; // 1 line
    for (unsigned i=0; i<layer_count; i++) {
        unsigned t;
        file >> t; // 2 line
        layers_neuron_count.push_back(t);
    }
    file >> issetWeight; // 3 line
    if (onlyScheme) issetWeight = false;
    for (unsigned i=0; i<layer_count; i++) { // for each layer
        ListNeuronP layer;
        ListDoubleP prevOutputs;
        if (i>0) prevOutputs = getOutputPointers(i-1);
        for (unsigned j=0; j<layers_neuron_count[i]; j++) { // for each neuron on layer
            unsigned weightCount;
            if (issetWeight) file >> weightCount;
            else weightCount = i>0 ? layers_neuron_count[i-1] : 1;
            Neuron* neuron = new Neuron();
            for (unsigned k=0; k<weightCount+1; k++) {
                double w;
                if (issetWeight) file >> w;
                else w = i==0 ? 1 : randone();
                if (k==weightCount) { // set bias
                    neuron->setBias(w);
                } else { // set i weight
                    neuron->setWeightAdd(w);
                }
            }
            if (i!=0) neuron->setInput(prevOutputs);
            layer.push_back(neuron);
        }
        layers.push_back(layer);
    }
    isReady = true;
    file.close();
}

void NeuralNetwork::saveToFile(string filename) {
    ofstream file(filename);
    if (!file.is_open()) return;
    file << layers.size() << endl;
    for (unsigned i=0; i<layers.size(); i++) {
        file << layers[i].size() << " ";
    }
    file << endl;
    if (isReady) {
        file << "1" << endl;
        for (unsigned i=0; i<layers.size(); i++) {
            for (unsigned j=0; j<layers[i].size(); j++) {
                file << layers[i][j]->getLength() << endl;
                for (unsigned k=0; k<layers[i][j]->getLength(); k++) {
                    file << layers[i][j]->getWeightAt(k) << " ";
                }
                file << layers[i][j]->getBias() << endl;
            }
        }
    } else {
        file << "0" << endl;
    }
    file.close();
}

void NeuralNetwork::print() {
    for (unsigned i=0; i<layers.size(); i++) {
        cout << "layer " << (i+1) << ": " << layers[i].size() << " neurons" << endl;
        for (unsigned j=0; j<layers[i].size(); j++) {
            cout << "neuron " << (j+1) << ": " << layers[i][j]->getLength() << ", bias=" << layers[i][j]->getBias() << endl;
            for (unsigned k=0; k<layers[i][j]->getLength(); k++) {
                cout << layers[i][j]->getWeightAt(k) << " ";
            }
            cout << endl;
        }
    }
}

ListDoubleP NeuralNetwork::getOutputPointers(unsigned n) {
    ListDoubleP outs;
    for (unsigned i=0; i<layers[n].size(); i++) {
        outs.push_back(layers[n][i]->getOutputPointer());
    }
    return outs;
}

void NeuralNetwork::setInput(ListDouble inputVector) {
    for (unsigned i=0; i<layers[0].size(); i++) {
        layers[0][i]->setInputAt(0, &(inputVector[i]));
        // cout << &(inputVector[i]) << " ";
    }
}

ListDouble NeuralNetwork::getOutput() {
    ListDouble result;
    unsigned lastLayer = layers.size()-1;
    for (unsigned i=0; i<layers[lastLayer].size(); i++) {
        result.push_back(layers[lastLayer][i]->getOutputValue());
    }
    return result;
}

void NeuralNetwork::printOutput(string filename) {
    ofstream file(filename);
    ListDouble result = getOutput();
    for (unsigned i=0; i<result.size(); i++)
        if (filename=="stdout") cout << result[i] << " ";
        else file << result[i] << " ";
    if (filename=="stdout") cout << endl;
    else {
        file << endl;
        file.close();
    }
}

void NeuralNetwork::process() {
    for (unsigned i=0; i<layers.size(); i++) {
        for (unsigned j=0; j<layers[i].size(); j++) {
            layers[i][j]->process();
        }
    }
}

ListNeuronP NeuralNetwork::getLayerAt(unsigned n) {
    return layers[n];
}

unsigned NeuralNetwork::getLayersCount() {
    return layers.size();
}

ListDouble NeuralNetwork::getDerivativesLayer(unsigned n) {
    ListDouble result;
    // cout << n << endl;//getLayerAt(n).size();
    for (unsigned i=0; i<getLayerAt(n).size(); i++) {
        result.push_back(getLayerAt(n)[i]->derivative(getLayerAt(n)[i]->getSummatorValue()));
    }
    return result;
}
