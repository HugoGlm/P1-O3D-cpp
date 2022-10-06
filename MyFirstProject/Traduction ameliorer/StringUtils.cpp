#include "StringUtils.h"
#include <algorithm>
using namespace std;

void StringUtils::Replace(string& _str, const char& _old, const char& _newValue)
{
	ranges::replace(_str, _old, _newValue);
}