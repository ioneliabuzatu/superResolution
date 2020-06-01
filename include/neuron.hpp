#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
unsing namespace std;

class NeuronUnit
{
public:
    NeuronUnit(double value);

    void activate_with__sigma_function(); // f(x) = x/(1+|x|)
    void derivative():

    void get_value() {return this-> value;}
    void get_activated_value() {return this->activated_value;}
    void get_derivative_activated_value() {return this->derivative_activated_value;}

private:
    double value:
    double activated_value;
    double derivative_activated_value;
};
