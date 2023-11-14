#ifndef _BML_DSP_FILE_TOOLS_H_
#define _BML_DSP_FILE_TOOLS_H_

#include <vector>
#include <string>

namespace BML
{
    namespace FileTools
    {
        template <typename T>
        inline void writeVecToCsv(const std::vector<T>& vec, std::string filename)
        {
            std::ofstream file;
            file.open(filename);
            if (file.is_open())
            {
                std::for_each(vec.begin(), vec.end(), [&file](const T val) {file << val << ",";});
                file.close();
            }
        }
    }
}

#endif