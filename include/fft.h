#include <vector>
#include <complex>
#include <fftw3.h>

namespace BML
{
    namespace FFT
    {
        std::vector<std::complex<double>> fft(std::vector<double> input);

        std::vector<double> ifft(std::vector<std::complex<double>> input);
    }
}