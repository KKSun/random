
#ifndef MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H
#define MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H

#include "rng.h"
#include "Eigen/Dense"
#include "Eigen/Cholesky"

using namespace Eigen;

struct MultivariateGaussian : Rng {

    int dim_;
    Map<const VectorXd> mean_;
    Map<const MatrixXd> cov_;
    LLT<MatrixXd> chol_;
    VectorXd spt_;

    MultivariateGaussian(const double* mean, int dim, const double* cov, int rows, int cols, unsigned long long seed);

    void dev(double* sample, int dim);
};

#endif //MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H
