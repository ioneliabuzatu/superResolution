#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include "../include/neuron.hpp"
#include <vector>

using namespace std;


class Layer {
public:

    Layer(int size);

private:
    int size;
    vector<NeuronUnit *> neurons;
};


#endif