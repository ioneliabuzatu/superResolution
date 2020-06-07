#ifndef __FC__HPP_
#define __FC__HPP_

#include <iostream>
#include "matrix.hpp"
#include "layer.hpp"

using namespace std;

class FC {
public:
    FC(vector<int> architecture);
    void set_input(vector<double> input);

private:

    vector<int> architecture;
    vector<Layer *> layers;
    vector<Matrix *> weighted_matrices;
    vector<double> input;
};


#endif