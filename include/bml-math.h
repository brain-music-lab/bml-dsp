#ifndef _BML_DSP_BML_MATH_H_
#define _BML_DSP_BML_MATH_H_

#define _USE_MATH_DEFINES
#include <cmath>

namespace BML
{
    namespace Math
    {
        inline size_t findGcd(size_t a, size_t b)
        {
            if (a == 0)
                return b;
                
            return findGcd(b % a, a);
        }

        inline size_t findLcm(size_t a, size_t b)
        { 
            size_t num = a * b;
            size_t den = findGcd(a, b);

            return num / den;
        }

        inline std::vector<double> arange(double start, double end, double step)
        {
            std::vector<double> out;

            while (start < end)
            {
                out.push_back(start);
                start += step;
            }

            return out;
        }
    }
}

#endif  // _BML_DSP_BML_MATH_H_
