#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

enum NeuronType {Input, Hidden, Output};
typedef vector<double*> ListDoubleP;
typedef vector<double>  ListDouble;

class Neuron {
private:
    double summator_value;
    double output;
    double bias;
    ListDoubleP input;
    ListDouble  weight;
public:
    /* constructor */
    Neuron(LisDoubleP i, ListDouble w, double b) {
        input = i;
        weight = w;
        bias = b;
        summator_value = output = 0;
    }
    /* input */
    ListDoubleP getInput() {
        return input;
    }
    double* getInputAt(unsigned p) {
        return input[p];
    }
    void setInput(ListDoubleP list) {
        input = list;
    }
    void setInputAt(unsigned p, double* v) {
        input[p] = v;
    }
    /* bias */
    double getBias() {
        return bias;
    }
    void setBias(double b) {
        bias = b;
    }
    /* weight */
    ListDouble getWeight() {
        return weight;
    }
    double getWeightAt(unsigned p) {
        return weight[p];
    }
    void setWeight(ListDouble list) {
        weight = list;
    }
    void setWeightAt(unsigned p, double v) {
        weight[p] = v;
    }
    /* output */
    double* getOutputPointer() {
        return &output;
    }
    double getOutputValue() {
        return output;
    }
    /* body */
    double summator() {
        double result = bias;
        for (unsigned i=0; i<input.size(); i++) {
            result += (*input[i]) * weight[i];
        }
        summator_value = result;
        return result;
    }
    double activator(double x) {
        return exp(-x);
    }
    double derivative(double x) {
        return exp(-x);
    }
    double getSummatorValue() {
        return summator_value;
    }
    /* other */
    void process();
};

typedef vector<Neuron*> ListNeuronP;
typedef vector<ListNeuronP> ListLayer;

class NeuralNetwork {
private:
    ListLayer layers;
    Neuron* factory();
public:
    NeuralNetwork();
    void loadFromFile(string filename) {
        ifstream file(filename);
        unsigned layer_count;
        vector<unsigned> layers_neuron_count;
        file >> layer_count;
        for (unsigned i=0; i<layer_count; i++) {
            unsigned t;
            file >> t;
            layers_neuron_count.push_back(t);
        }
        for (unsigned i=0; i<layer_count; i++) {
            ListNeuronP layer;
            for (unsigned j=0; j<layers_neuron_count[i]; j++) {
                Neuron* neuron = new Neuron();
                neuron->
            }
            layers.push_back(layer);
        }
    }
    void saveToFile(string);
};

class Learning {
private:
    double speed;
    unsigned iteration;
    NeuralNetwork* network;
public:
    Learning(NeuralNetwork* target, double s) {
        speed = s;
        iteration = 0;
        network = target;
    }
    void algorithmBackPropagation(ListDoubleP learning_data, double teacher, unsigned iteration_count) {
        for (unsigned i=1; i<=iteration_count; i++) {
            iteration++;
            //
        }
    }
    void testBackPropagation();
};

int main(int argc, char** argv) {
    return 0;
}
