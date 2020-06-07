#include "../include/layer.hpp"
#include "../include/matrix.hpp"


Matrix *Layer::flatten_matrix_values() {
    Matrix *matrix_ = new Matrix(1, this->neurons.size());
    for (int neuron_ = 0; neuron_ < neurons.size(); neuron_++) {
        matrix_->set_value(1, neuron_, this->neurons.at(neuron_)->get_value());
    }
}

Matrix *Layer::flatten_matrix_activated_values() {
    Matrix *matrix_ = new Matrix(1, this->neurons.size());
    for (int neuron_ = 0; neuron_ < neurons.size(); neuron_++) {
        matrix_->set_value(1, neuron_, this->neurons.at(neuron_)->get_activated_value());
    }
}

Matrix *Layer::flatten_matrix_derivative_values() {
    Matrix *matrix_ = new Matrix(1, this->neurons.size());
    for (int neuron_ = 0; neuron_ < neurons.size(); neuron_++) {
        matrix_->set_value(1, neuron_, this->neurons.at(neuron_)->get_derivative_activated_value());
    }
}


Layer::Layer(int size) {
    this->size = size;
    for (int neuron_index = 0; neuron_index < size; neuron_index++) {
        NeuronUnit *neuron_unit = new NeuronUnit(0.1);
        this->neurons.push_back(neuron_unit);
    }

}


void Layer::set_value_(int value_index, double value) {
    this->neurons.at(value_index)->set_value_(value);
}