//
// Created by tipakorng on 5/10/16.
//

#ifndef MULTIVARIATE_GAUSSIAN_RNG_H
#define MULTIVARIATE_GAUSSIAN_RNG_H

struct Rng {
    unsigned long long v;

    Rng(unsigned long long j) : v(4101842887655122017LL) {
        v ^= j;
        v = int64();
    }

    inline unsigned long long int64() {
        v ^= v >> 21;
        v ^= v << 35;
        v ^= v >> 4;
        return v * 2685821657736338717LL;
    }

    inline double doub() {
        return 5.42101086242752217E-20 * int64();
    }

    inline unsigned int int32() {
        return static_cast<unsigned int>(int64());
    }
};

#endif //MULTIVARIATE_GAUSSIAN_RNG_H
