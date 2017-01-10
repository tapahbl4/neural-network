#include "headers/Network.hpp"

Network::Network() {
    //this->scheme.open(filename);
}

void Network::open(string filename) {
    ifstream scheme;
    scheme.open(filename);
    int countLayer;
    vector<double*> currOut, prevOut;
    vector<int> countNeurons;
    scheme >> countLayer;
    for (int i=0; i<countLayer; i++) {
        int t;
        scheme >> t;
        countNeurons.push_back(t);
    }
    for (int i=0; i<countLayer; i++) {
        Layer* layer = new Layer();
        //cout << "layer " << i << ", neurons: " << countNeuron << endl;
        for (int j=0; j<countNeurons[i]; j++) {
            NeuronType type = i==0 ? NeuronType::Input : (i+1==countLayer ? NeuronType::Output : NeuronType::Hidden);
            Neuron* neuron = new Neuron(type);
            currOut.push_back(&neuron->output);
            int countWeight;
            vector<double> weight(i==0 ? 1 : countNeurons[i-1], ((double) rand() / (RAND_MAX)));
            if (scheme >> countWeight) {
                weight.clear();
                for (int k=0; k<countWeight; k++) {
                    double w;
                    scheme >> w;
                    weight.push_back(w);
                }
            }
            neuron->setInput(0, prevOut, weight);
            layer->addNeuron(neuron);
        }
        layers.push_back(layer);
        prevOut = currOut;
        currOut.clear();
    }
    cout << "arch is created" << endl;
    scheme.close();
}

void Network::setWeight(string filename) {

}

void Network::printAll() {
    for (unsigned i=0; i<layers.size(); i++) {
        cout << "layer " << i << ": (" << layers[i]->neurons.size() << ")" << endl;
        for (unsigned j=0; j<layers[i]->neurons.size(); j++) {
            cout << "neuron " << j << ": " << endl;
            for (unsigned k=0; k<layers[i]->neurons[j]->input.size(); k++) {
                cout << "(" << (*layers[i]->neurons[j]->input[k]) << "; " << layers[i]->neurons[j]->weight[k] << "), ";
            }
            cout << "\noutput: " << layers[i]->neurons[j]->output << endl;
        }
    }
}

void Network::save(string filename) {
    ofstream scheme;
    scheme.open(filename);
    scheme << layers.size() << endl;
    for (unsigned i=0; i<layers.size(); i++) {
        scheme << layers[i]->neurons.size() << " ";
    }
    scheme << endl;
    for (unsigned i=0; i<layers.size(); i++) {
        for (unsigned j=0; j<layers[i]->neurons.size(); j++) {
            scheme << layers[i]->neurons[j]->weight.size() << endl;
            for (unsigned k=0; k<layers[i]->neurons[j]->weight.size(); k++) {
                scheme << layers[i]->neurons[j]->weight[k] << " ";
            }
            scheme << endl;
        }
    }
    scheme.close();
}

vector<double> Network::process(vector<double> input) {
    for (unsigned i=0; i<input.size(); i++) {
        layers[0]->neurons[i]->input.push_back(&input[i]);
    }
    for (unsigned i=0; i<layers.size(); i++) {
        layers[i]->process();
    }
    return layers[layers.size()-1]->getOutput();
}
