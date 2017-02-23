#include "../include/multivariate_gaussian.h"


MultivariateGaussian::MultivariateGaussian(const double* mean, int dim, const double* cov, int rows, int cols, 
                                           unsigned long long seed) :
    Rng(seed),
    dim_(dim),
    mean_(mean, dim),
    cov_(cov, rows, cols),
    chol_(cov_),
    spt_(dim)
{}

MultivariateGaussian::MultivariateGaussian(const Eigen::VectorXd &mean, const Eigen::MatrixXd &cov, unsigned long long seed) :
    Rng(seed),
    dim_(mean.size()),
    mean_(mean.data(), mean.size()),
    cov_(cov.data(), cov.rows(), cov.cols()),
    chol_(cov_),
    spt_(dim_)
{}

void MultivariateGaussian::dev(double* sample, int dim)
{
    Eigen::Map<Eigen::VectorXd> map(sample, dim_);
    dev(map);
}
