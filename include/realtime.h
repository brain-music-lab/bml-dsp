#include <fft.h>
#include <cassert>
#include <memory>

namespace BML
{
    namespace RealTime
    {
        struct RationalFactor
        {
            size_t upsample;
            size_t downsample;
        };
        
        RationalFactor findRationalFactor(size_t oldFs, size_t newFs);

        class Convolution
        {
        public:

            enum class Method
            {
                OVERLAP_ADD,
                OVERLAP_SAVE
            };

            Convolution(const std::vector<double>& lpf, Method method = Method::OVERLAP_ADD);

            std::vector<double> convolve(const std::vector<double>& block);

        private:
            std::vector<double> m_lpf;
            size_t m_filterSize;
            std::vector<double> m_overlap;
            Method m_convMethod;

            std::vector<double> overlapAdd(const std::vector<double>& block);

            std::vector<double> overlapSave(const std::vector<double>& block);
        };

        class Resample
        {
        public:
            Resample(double oldFs, double newFs);

            std::vector<double> resample(const std::vector<double>& block);

        private:
            std::vector<double> zeroPad(const std::vector<double>& vector_to_pad, int num_zeros);

            double m_oldFs;
            double m_newFs;
            RationalFactor m_rationalFactor;

            std::unique_ptr<Convolution> m_convolutionUp;
            std::unique_ptr<Convolution> m_convolutionDown;

        };
    }
}