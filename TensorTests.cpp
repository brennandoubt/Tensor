#include "Tensor.h"


void Test1() {
    cout << "RUNNING TEST 1...\n";
    Tensor* t1 = new Tensor();

    delete t1;
    cout << "EXITING TEST 1...\n";
}

void Test2() {
    // "batches" of inputs to add to network
    vector<vector<double> > inputs = {
        {1, 2, 3, 2.5},
        {2.0, 5.0, -1.0, 2.0},
        {-1.5, 2.7, 3.3, -0.8}
    };

    vector<vector<double> > weights = {
        {0.2, 0.8, -0.5, 1.0},
        {0.5, -0.91, 0.26, -0.5},
        {-0.26, -0.27, 0.17, 0.87}
    };

    vector<double> biases = {2, 3, 0.5};

    Tensor t_inputs = Tensor(inputs);
    Tensor t_weights = Tensor(weights);

    cout << t_inputs.to_string() << endl;
    cout << t_weights.to_string() << endl;

    cout << t_inputs.shape() << endl;
    cout << t_weights.shape() << endl;

    t_weights = t_weights.transpose();
    cout << t_weights.to_string() << '\n' << t_weights.shape() << endl;

    Tensor product = t_inputs * t_weights;
    cout << product.to_string() << endl;
}


int main() {
    Test1();
    Test2();

    return 0;
}