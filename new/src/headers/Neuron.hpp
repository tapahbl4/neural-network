#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>

enum NeuronType {Input, Hidden, Output};
typedef std::vector<double*> ListDoubleP;
typedef std::vector<double>  ListDouble;

using namespace std;

class Neuron {
private:
    double summator_value;
    double output;
    double bias;
    ListDoubleP input;
    ListDouble  weight;
public:
    /* constructor */
    Neuron(ListDoubleP, ListDouble, double);
    /* input */
    ListDoubleP getInput();
    double* getInputAt(unsigned);
    void setInput(ListDoubleP);
    void setInputAt(unsigned, double*);
    /* bias */
    double getBias();
    void setBias(double);
    /* weight */
    ListDouble getWeight();
    double getWeightAt(unsigned);
    void setWeight(ListDouble);
    void setWeightAt(unsigned, double);
    /* output */
    double* getOutputPointer();
    double getOutputValue();
    /* body */
    double summator();
    double activator(double);
    double derivative(double);
    double getSummatorValue();
    /* other */
    void process();
};

#endif
