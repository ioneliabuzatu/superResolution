#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"

using namespace std;


class Layer {
public:

    Layer(int size);
    void set_value_(int index, double value);

    Matrix *flatten_matrix_values();
    Matrix *flatten_matrix_activated_values();
    Matrix *flatten_matrix_derivative_values();
private:
    int size;
    vector<NeuronUnit *> neurons;
};


#endif