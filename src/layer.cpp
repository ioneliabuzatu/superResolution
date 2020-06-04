#include "../include/layer.hpp"


Layer::Layer(int size) {
    this->size = size;
    for (int neuron_index = 0; neuron_index < size; neuron_index++) {
        NeuronUnit *neuron_unit = new NeuronUnit(0.1);
        this->neurons.push_back(neuron_unit);
    }


}