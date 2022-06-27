#pragma once
#include "evalmap.h"
#define A(...) EVAL(MAP(Α, __VA_ARGS__))
#define B(...) EVAL(MAP(Β, __VA_ARGS__))
