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

template<typename Derived>
void MultivariateGaussian::dev(Eigen::MatrixBase<Derived> &sample)
{
    int i;
    double u, v, x, y, q;

    for (i = 0; i < dim_; i++)
    {
        do
        {
            u = doub();
            v = 1.7156 * (doub()-0.5);
            x = u - 0.449871;
            y = std::abs(v) + 0.386595;
            q = pow(x, 2) + y * (0.19600 * y - 0.25472 * x);
        } while (q > 0.27597 && (q > 0.27846 || pow(v, 2) > -4.0*log(u)*pow(u, 2)));

        spt_(i) = v/u;
    }

    sample.resize(dim_);
    sample = chol_.matrixL() * spt_ + mean_;
}
