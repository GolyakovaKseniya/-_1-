#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//FIX_ME: непонятное название параметров функции, должны быть переданы по const-ссылке
// a, b
//FIX_ME: неправильно стоит фигурная скобка 
//FIX_ME: неправильное название функции для bool
//SortWeight
bool IsLighterThan(const FArtifact& First, const FArtifact& Second)
{
	return First.Weight < Second.Weight;
}