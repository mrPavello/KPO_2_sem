#include "Varparm.h"
#include <locale>

namespace Varparm {
    int ivarparm(int k, ...) {
        if (k > 0) {
            int* ptr = &k;
            int i = 2;
            int res = *(ptr + i);
            for (; i <= k; i++) {
                res *= *(ptr + i * 2);
            }
            return res;
        }
        else {
            return 0;
        }
    }
    int svarparm(short k, ...) {
        if (k > 0) {
            int max;
            int* ptr = (int*)(&k);
            int i = 2;
            max = *(ptr + i);
            for (; i <= k; i++) {
                if (max < *(ptr + 2 * i))
                    max = *(ptr + 2 * i);
            }
            return max;
        }
        else {
            return 0;
        }
    }
    double fvarparm(float k, ...) {
        if (k != FLT_MAX) {
            double* ptr = (double*)(&k);
            double sum = k;
            int i = 1;
            while (ptr[i] != (double)FLT_MAX) {
                sum += *(ptr + i);
                i++;
            }
            return sum;
        }
        else {
            return 0;
        }
    }
    double dvarparm(double k, ...) {
        if (k != DBL_MAX) {
            double* ptr = (double*)(&k);
            double sum = k;
            int i = 1;
            while (ptr[i] != (double)DBL_MAX) {
                sum += *(ptr + i);
                i++;
            }
            return sum;
        }
        else {
            return 0;
        }
    }
}
