#ifndef TENSOR_H
#define TENSOR_H
/**
 * @file Tensor.h
 * @author Brennan (brennandoubt@gmail.com)
 * @brief Header file for n-D array object class
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
using namespace std;

// technically just a Matrix class currently since the data type is hard-coded to a 2-D array
class Tensor {

    public:
        // constructor - can initialize array holding tensor data
        Tensor() { this->array = {}; };
        Tensor(const vector<vector<double> >& arr) { this->array = arr; };

        // using matrix multiplication algorithm
        Tensor operator*(const Tensor& other);

        // printing out tensor data to terminal
        string to_string();

        // printing out dimensions of tensor (in tuple (x, y) format)
        string shape();

        

    private:
        vector<vector<double> > array; // holds tensor data
        
        template <typename T>
        string vec_to_string(vector<T>& v); // used by public to_string method

};

#include "Tensor.cpp" // to fix linker error when using templates

#endif