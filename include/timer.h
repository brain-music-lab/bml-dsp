#include <string>
#include <chrono>
#include <iostream>

namespace BML
{
    namespace Benchmark
    {
        class Stopwatch
        {
        public:
            Stopwatch(std::string message) :
                m_mess(message)
            {
                m_startTp = std::chrono::high_resolution_clock::now();
            }

            ~Stopwatch()
            {
                auto endTp = std::chrono::high_resolution_clock::now();
                auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTp).time_since_epoch().count();
                auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTp).time_since_epoch().count();

                auto duration = end - start;
                double ms = duration * 0.001;

                std::cout << m_mess << ": " << ms << "ms elapsed.\n";
            }

        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> m_startTp;
            std::string m_mess;
        };
    }
}