#pragma once
#include "evalmap.h"
#define OA(...) EVAL(MAP(Oa, __VA_ARGS__))
#define NA(...) EVAL(MAP(Na, __VA_ARGS__))
