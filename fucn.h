#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// Сортування масиву у зростаючому порядку
inline void sortAsc(vector<int>& v)
{
	for(int i = 0; i < v.size() - 1; i++)
	{
		for(int j = 0; j < v.size() - i - 1; j++)
		{
			if(v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// Сортування масиву у спадному порядку
inline void sortDesc(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] < v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

// Підрахунок суми елементів масиву
inline int sumOfElements(vector<int>& v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	return sum;
}

// Функція для видалення однакових елементів з масиву, та переніс їх в інший масив
inline void rmDuplicates(vector<int>& v, vector<int>& unique)
{
	unique.clear();
	for (int i = 0; i < v.size(); i++)
	{
		bool isDuplicate = false;
		for (int j = 0; j < unique.size(); j++)
		{
			if (v[i] == unique[j])
			{
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate)
		{
			unique.push_back(v[i]);
		}
	}
}

// Функція для виводу різниці масивів |V1 - V2| (елементи, які були видалені)
inline void printDifference(vector<int>& v1, vector<int>& v2)
{
	for (int i = 0; i < v1.size(); i++)
	{
		int count = 0;

		for (int j = 0; j < v1.size(); j++)
		{
			if (v1[i] == v1[j])
				count++;
		}

		if (count > 1)
			cout << v1[i] << " ";
	}

	cout << endl;
}

// Функція для запису результатів у файл json
inline void JsonOut(ofstream& jout, int sum2, int sum3, int duplicatesCount, vector<int>& v1, vector<int>& v2)
{
	// Створюємо об'єкт json
	json j;

	// Заповнюємо даними (бібліотека сама конвертує vector у JSON array)
	j["S2"] = sum2;
	j["S3"] = sum3;
	j["S3 - S2"] = sum3 - sum2;
	j["duplicatesCount"] = duplicatesCount;
	j["V1"] = v1;
	j["V2"] = v2;

	// Записуємо у файл із відступами (4 пробіли), щоб було зручно читати
	jout << j.dump(4) << endl;
}