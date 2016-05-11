
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

    MultivariateGaussian(const double* mean, int dim, const double* cov, int rows, int cols, unsigned long long seed) :
        Rng(seed),
        dim_(dim),
        mean_(mean, dim),
        cov_(cov, rows, cols),
        chol_(cov_),
        spt_(dim){
    }

    void dev(double* sample, int dim) {
        int i;
        double u, v, x, y, q;

        for (i = 0; i < dim_; i++) {
            do {
                u = doub();
                v = 1.7156 * (doub()-0.5);
                x = u - 0.449871;
                y = std::abs(v) + 0.386595;
                q = pow(x, 2) + y * (0.19600 * y - 0.25472 * x);
            } while (q > 0.27597 && (q > 0.27846 || pow(v, 2) > -4.0*log(u)*pow(u, 2)));

            spt_(i) = v/u;
        }

        Map<VectorXd> pt(sample, dim_);
        pt = chol_.matrixL() * spt_ + mean_;
    }
};

#endif //MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H
