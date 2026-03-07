/*
Умова завдання
{...} - зроблено
{1.  Користувач вводить розмір масиву size.}
{2.  Створити масив V1 з size елементів та заповнити його випадковими
    цілими числами.}
{3.  Вивести масив на екран.}
{4.  Користувач вводить число n.}
{5.  Поділити масив V1 на групи по n елементів.} 

{6.  Для кожної групи обчислити суму елементів: S1 = x1 + x2 + … + xn S2
    = …}
{7.  Записати всі отримані суми у текстовий файл e.txt.
}
{8.  Відсортувати масив V1 за зростанням (ASC) та знайти суму всіх
    елементів.}
{9.  Відсортувати масив V1 за спаданням (DESC) та знайти суму всіх
    елементів.}
{10. Видалити повторювані елементи з масиву V1 та створити новий масив
    V2.}
{11. Обчислити суму елементів нового масиву V2 (S3).
}
{12. Знайти різницю сум: S3 - S2.
}
{13. Порахувати кількість елементів, які повторювалися у початковому
масиві.}
{14. Зберегти результати у JSON файл:
    -   S2
    -   S3
    -   S3 - S2
    -   кількість повторюваних елементів
    -   масив V1
    -   масив V2}
{15. Вивести на екран різницю масивів |V1 - V2| (елементи, які були
    видалені).}
*/

#include "fucn.h"

int main()
{
    srand(time(0));

    ofstream out("e.txt");
    ofstream jout("data.json");

    int size;
    int n;

    cout << "Enter size of array: ";
    cin >> size;

	// Створення масиву V1 та заповнення його випадковими числами
    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
		v1[i] = rand() % 99 + 1;
    }

	// Вивід масиву на екран
	cout << "Array V1: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

	cout << "Enter n: ";
    cin >> n;

	// Вивід сум для кожної групи по n елементів
    out << "Summed numbers:" << endl;
    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i + j < v1.size()) {
                sum += v1[i + j];
            }
        }
        out << sum << endl;
    }
    cout << endl;
	// Сортування масиву за зростанням та вивід на екран
	sortAsc(v1);
    cout << "Sorted array V1(ASC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "Sum of elements (ASC): " << sumOfElements(v1);
	int sum2 = sumOfElements(v1);
    cout << endl;
    cout << endl;

	// Сортування масиву за спаданням та вивід на екран
    sortDesc(v1);
    cout << "Sorted array V1(DESC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
	cout << endl << "Sum of elements (DESC): " << sumOfElements(v1);
    cout << endl;
    cout << endl;

	// Видалення повторюваних елементів та створення нового масиву V2, та створення копії масиву V1 для подальшого виводу різниці масивів
	vector<int> copyV1 = v1;
	rmDuplicates(v1, v2);
	// Сума елементів нового масиву V2
	int sum3 = sumOfElements(v2);
    cout << endl;

	// Різниця сум S3 - S2
	cout << "Difference of sums S3 - S2: " << sum3 - sum2 << endl;

	// Підрахунок кількості повторюваних елементів
	int sizeV2 = v2.size();
	int duplicatesCount = size - sizeV2;

	// Вивід різниці масивів |V1 - V2| (елементи, які були видалені)
    cout << "Difference of arrays |V1 - V2|: ";
	printDifference(copyV1, v2);
    cout << endl;

    // Запис результатів у JSON файл
    JsonOut(jout, sum2, sum3, duplicatesCount, v1, v2);

	// Закриття файлу
    out.close();
	jout.close();
}