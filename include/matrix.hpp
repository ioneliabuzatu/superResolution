#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
#include <random>

using namespace std;

class Matrix {
public:
    Matrix(int num_rows, int num_cols);

    Matrix *transpose_matrix();
    double random_numbers_generator();

    void set_value(int row_index, int col_index, int nsert_value);
    void get_value(int row_index, int col_index);

    void print_matrix_to_stdout();

    int get_num_rows() {return this->num_rows;}
    int get_num_cols() {return this->num_cols;}
private:
    int num_rows;
    int num_cols;
    vector<vector<double>> values;
};

#endif