#pragma once

#if 1
#include <iostream>

#define DEBUG

#define LOG(x) std::cout << x << std::endl
#define WARNING(x) std::cout << "[WARNING]: " << x << std::endl
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl

#else

#define LOG(x)
#define WARNING(x)
#define ERROR(x)

#endif