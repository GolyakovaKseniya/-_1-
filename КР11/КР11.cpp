#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	//FIX_ME: используем setlocale(LC_ALL, "")
	//setlocale(0, "");
	setlocale(LC_ALL, "");

	//FIX_ME: непонятное название переменной
	//f1
	std::ifstream InputFile;
	InputFile.open("f.txt");

	if (!InputFile.is_open())
	{
		std::cout << "Не удалось открыть файл f.txt(" << std::endl;
		return 1;
	}

	//FIX_ME: непонятное название переменных
	//n, b, sumw, sumv, k, maxw, maxv
	int32_t ArtifactCount = 0;
	int32_t MaxTotalWeight = 0;
	int32_t CurrentWeight = 0, CurrentVolume = 0, StartIndex = 0, BestWeight = 0, BestVolume = 0;

	//FIX_ME: нет проверки на считывание количества артефактов из файла
	/*InputFile >> ArtifactCount >> MaxTotalWeight;*/
	InputFile >> ArtifactCount;

	if (InputFile.fail())
	{
		std::cout << "Ошибка: не удалось прочитать количество артефактов" << std::endl;
		return 1;
	}

	//FIX_ME: нет проверки на ограничение количества артефактов
	const int32_t MAX_ARTIFACTS = 1000;
	if (ArtifactCount <= 0 || ArtifactCount > MAX_ARTIFACTS)
	{
		std::cout << "Ошибка: количество артефактов должно быть от 1 до " << MAX_ARTIFACTS << std::endl;
		return 1;
	}

	//FIX_ME: нет проверки на считывание максимального веса из файла
	//InputFile >> ArtifactCount >> MaxTotalWeight;

	if (InputFile.fail())
	{
		std::cout << "Ошибка: не удалось прочитать максимальный вес" << std::endl;
		return 1;
	}

	//FIX_ME: нет проверки на ограничение максимального веса
	if (MaxTotalWeight <= 0 || MaxTotalWeight >= 100000)
	{
		std::cout << "Ошибка: максимальный вес должен быть положительным и не превышать 100000" << std::endl;
		return 1;
	}

	std::vector<FArtifact> artifacts(ArtifactCount);

	//FIX_ME: добавим вектор для хранения наборов текущих и итоговых индексов
	std::vector<int32_t> BestIndices;
	std::vector<int32_t> CurrentIndices(ArtifactCount);
	int32_t CurrentCount = 0;

	//FIX_ME: постфиксный ++
	//i++
	//FIX_ME: нет сохранения исходного индекса
	//InputFile >> artifacts[i].Weight;
	for (int32_t i = 0; i < ArtifactCount; ++i)
	{
		InputFile >> artifacts[i].Weight;

		//FIX_ME: нет проверки на соответствующее количество весов артефактов
		//artifacts[i].OriginalIndex = i + 1;
		if (InputFile.fail())
		{
			std::cout << "Ошибка: не хватает данных для весов артефактов" << std::endl;
			return 1;
		}

		//FIX_ME: нет проверки на ограничение веса
		//artifacts[i].OriginalIndex = i + 1;
		if (artifacts[i].Weight < 0 || artifacts[i].Weight > 1000)
		{
			std::cout << "Ошибка: вес артефакта не может быть отрицательным или больше 1000" << std::endl;
			return 1;
		}

		artifacts[i].OriginalIndex = i + 1;
	}

	for (int32_t i = 0; i < ArtifactCount; ++i)
	{
		InputFile >> artifacts[i].Volume;

		//FIX_ME: нет проверки на соответствующее количество объема артефактов
		if (InputFile.fail())
		{
			std::cout << "Ошибка: не хватает данных для объёмов артефактов" << std::endl;
			return 1;
		}

		//FIX_ME: нет проверки на ограничение объема
		if (artifacts[i].Volume < 0 || artifacts[i].Volume > 100000)
		{
			std::cout << "Ошибка: объём артефакта не может быть отрицательным или больше 100000" << std::endl;
			return 1;
		}
	}

	//FIX_ME: нет проверки на наличие лишних данных в файле перед сортировкой
	//std::sort(artifacts.begin(), artifacts.end(), IsLighterThan)
	std::string ExtraData;
	InputFile >> ExtraData;
	if (!InputFile.fail())
	{
		std::cout << "Ошибка: в файле есть лишние данные после матрицы" << std::endl;
		return 1;
	}

	//FIX_ME: отсутствует метод закрытия файла
	//std::ifstream InputFile;
	//InputFile.open("f.txt");
	InputFile.close();

	std::sort(artifacts.begin(), artifacts.end(), IsLighterThan);

	while (StartIndex < ArtifactCount)
	{
		CurrentWeight = 0;
		CurrentVolume = 0;
		CurrentCount = 0;
		for (int32_t j = StartIndex; j < ArtifactCount; ++j)
		{
			if (artifacts[j].Weight + CurrentWeight <= MaxTotalWeight)
			{
				CurrentWeight += artifacts[j].Weight;
				CurrentVolume += artifacts[j].Volume;
				CurrentIndices[CurrentCount++] = artifacts[j].OriginalIndex;

				if (BestWeight < CurrentWeight)
				{
					BestWeight = CurrentWeight;
					BestVolume = CurrentVolume;

					BestIndices.clear();

					for (int32_t k = 0; k < CurrentCount; ++k)
					{
						BestIndices.push_back(CurrentIndices[k]);
					}
				}
				else if (BestWeight == CurrentWeight && CurrentCount > BestIndices.size())
				{
					BestVolume = CurrentVolume;
					BestIndices.clear();

					for (int32_t k = 0; k < CurrentCount; ++k)
					{
						BestIndices.push_back(CurrentIndices[k]);
					}
				}
			}
		}
		if (BestWeight == MaxTotalWeight)
		{
			break;
		}
		else
		{
			++StartIndex;
		}

	}

	//FIX_ME: нет финальной проверки на пустоту
	if (BestIndices.empty())
	{
		std::cout << "Не удалось выбрать артефакты" << std::endl;
		return 1;
	}

	std::sort(BestIndices.begin(), BestIndices.end());

	//FIX_ME: перед выводом веса и объема выбранных артефактов нет вывода их порядковых номеров
	//std::cout << "Максимальный вес артефактов = " << BestWeight << "\n" << "Объем взятых артефактов = " << BestVolume;
	//return 0;
	std::cout << "Порядковые номера артефактов: ";

	for (int32_t i : BestIndices)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	std::cout << "Максимальный вес артефактов = " << BestWeight << "\n" << "Объем взятых артефактов = " << BestVolume;
	return 0;
}