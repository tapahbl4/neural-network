#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <cmath>
#include <iostream>

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
    /* Constructors */
    Neuron();
    Neuron(ListDoubleP, ListDouble, double);

    /**
     * [getInput description]
     * @return [description]
     */
    ListDoubleP getInput();

    /**
     * [getInputAt description]
     * @param  unsigned [description]
     * @return          [description]
     */
    double* getInputAt(unsigned);

    /**
     * [setInput description]
     * @param ListDoubleP [description]
     */
    void setInput(ListDoubleP);

    /**
     * [setInputAt description]
     * @param unsigned [description]
     * @param [name]   [description]
     */
    void setInputAt(unsigned, double*);

    /**
     * [getBias description]
     * @return [description]
     */
    double getBias();

    /**
     * [setBias description]
     * @param double [description]
     */
    void setBias(double);

    /**
     * [correctBias description]
     * @param double [description]
     */
    void correctBias(double);

    /**
     * [getWeight description]
     * @return [description]
     */
    ListDouble getWeight();

    /**
     * [getWeightAt description]
     * @param  unsigned [description]
     * @return          [description]
     */
    double getWeightAt(unsigned);

    /**
     * [setWeight description]
     * @param ListDouble [description]
     */
    void setWeight(ListDouble);

    /**
     * [setWeightAt description]
     * @param unsigned [description]
     * @param double   [description]
     */
    void setWeightAt(unsigned, double);

    /**
     * [setWeightAdd description]
     * @param double [description]
     */
    void setWeightAdd(double);

    /**
     * [correctWeightAt description]
     * @param unsigned [description]
     * @param double   [description]
     */
    void correctWeightAt(unsigned, double);

    /**
     * [getOutputPointer description]
     * @return [description]
     */
    double* getOutputPointer();

    /**
     * [getOutputValue description]
     * @return [description]
     */
    double getOutputValue();

    /**
     * [summator description]
     * @return [description]
     */
    double summator();

    /**
     * [activator description]
     * @param  double [description]
     * @return        [description]
     */
    double activator(double);

    /**
     * [derivative description]
     * @param  double [description]
     * @return        [description]
     */
    double derivative(double);

    /**
     * [getSummatorValue description]
     * @return [description]
     */
    double getSummatorValue();

    /**
     * [getLength description]
     * @return [description]
     */
    unsigned getLength();

    /**
     * [process description]
     */
    void process();
};

#endif
