//
// Created by tipakorng on 5/10/16.
//

#ifndef MULTIVARIATE_GAUSSIAN_RNG_H
#define MULTIVARIATE_GAUSSIAN_RNG_H

/**
 * \brief This struct implements Ranq1 in Numerical Recipe, 3rd edition.
 */
struct Rng {

    unsigned long long v;

    Rng(unsigned long long j);

    unsigned long long int64();

    double doub();

    unsigned int int32();
};

#endif //MULTIVARIATE_GAUSSIAN_RNG_H
