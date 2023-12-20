#include <lsl_cpp.h>
#include <mutex>

typedef void (*callback)();

void getLslBlocks(const std::string& prop, 
				  const std::string& type, 
				  std::vector<std::vector<double>>& block,
				  std::mutex& mut,
				  std::atomic_bool* running,
				  callback callbackFn,
				  double timeout = LSL_FOREVER);
