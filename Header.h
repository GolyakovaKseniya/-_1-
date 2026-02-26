#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>
//FIX_ME: Запрещено использовать using namespace std
//using namespace std;

//FIX_ME: Для простых структур нужен префикс F
//Artifact
//FIX_ME: программа не выводит порядковые номера вещей, которые надо взять
struct FArtifact
{
	//FIX_ME: поля публичных структур с маленькой буквы
	//int weight; 
	//int volume;
	//FIX_ME: указан неточный размер
	//int
	int32_t Weight;
	int32_t Volume;
	int32_t OriginalIndex;
};

//FIX_ME: непонятное название параметров функции, должны быть переданы по const-ссылке
// a, b
//FIX_ME: неправильно стоит фигурная скобка 
//FIX_ME: неправильное название функции для bool
//SortWeight
bool IsLighterThan(const FArtifact& First, const FArtifact& Second);