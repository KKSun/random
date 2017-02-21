
#ifndef MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H
#define MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H

#include "rng.h"
#include "Eigen/Dense"
#include "Eigen/Cholesky"

/**
 * \brief This struct generates random vectors sampled from a multivariable Gaussian distribution.
 *        It implements multinormaldev in Numerical Recipe, 3rd edition.
 */
struct MultivariateGaussian : Rng {

    int dim_;
    Eigen::Map<const Eigen::VectorXd> mean_;
    Eigen::Map<const Eigen::MatrixXd> cov_;
    Eigen::LLT<Eigen::MatrixXd> chol_;
    Eigen::VectorXd spt_;

    MultivariateGaussian(const double* mean, int dim, const double* cov, int rows, int cols, unsigned long long seed);

    MultivariateGaussian(const Eigen::VectorXd &mean, const Eigen::MatrixXd &cov, unsigned long long seed);

    void dev(double* sample, int dim);

    template<typename Derived>
    void dev(Eigen::MatrixBase<Derived> &sample);
};

#endif //MULTIVARIATE_GAUSSIAN_MULTIVARIATE_GAUSSIAN_H
