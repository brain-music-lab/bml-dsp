#ifndef _BML_DSP_FILTER_H_
#define _BML_DSP_FILTER_H_

#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>


namespace BML
{
    namespace Filter
    {
        double findMaxBandwidth(double fs, double fc);

        double findMinBandwidth(size_t inputSize);

        bool checkBwValidity(double fs, double fc, double proposedBw);

        enum class Window
        {
            RECTANGULAR,
            BLACKMAN,
            HAMMING,
            KAISER
        };

        std::vector<double> createLowPassFilter(double samplerate, double cutoffFreq, double transitionBand, Window window = Window::BLACKMAN);
    }
}

#endif  // _BML_DSP_FILTER_H_