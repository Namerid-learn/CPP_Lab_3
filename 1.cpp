#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int array_size; 
    int count_pozitive = 0;
    int count_after_zero = 0;
    int sum_after_zero = 0;

    cout << "Введите размер массива (вещественное): ";
    cin >> array_size;

    if (cin.fail() || array_size <= 0) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    int *A = new int[array_size];

    srand(time(0));
    for (int i = 0; i < array_size; i++)
    {   
        * (A + i) = (rand() % 40) - 20;
    }

    cout << endl << "Массив: \n";
    for(int *ptr = A; ptr < (A + array_size); ptr++)
    {
        cout << *ptr << " ";
    }

    for (int *ptr = A; ptr < (A + array_size); ptr++)
    {
        if (*ptr > 0) {
            count_pozitive++;
        }
    }

    cout << endl << endl << "Количество положительных элементов массива: " << count_pozitive << endl << endl;

    int *ref_to_zero_el = nullptr;
    int after_zero_array_size = 0;

    for (int *ptr = A + array_size - 1; ptr >= A; ptr--)
    {
        if (*ptr == 0) {
            ref_to_zero_el = ptr;
            break;
        }
        else {
            after_zero_array_size++;
        }
        
    }

    if (ref_to_zero_el == nullptr) {
        cout << "В массиве нет нулевых элементов" << endl;
    } 
    else {
        for (int *ptr = ref_to_zero_el; ptr <= (ref_to_zero_el + after_zero_array_size); ptr++)
        {
            sum_after_zero += *ptr;
        }

        cout << "Сумма элементов после нулевого: " << sum_after_zero << endl;
    } 

    int sort_array_size = array_size;
    int *R = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        *(R + i) = *(A + i);
    }
    

    while(sort_array_size--)
	{   
		bool swapped = false;
		
		for(int *ptr = R; ptr < (R + array_size); ptr++)
		{
			if(*ptr < *(ptr + 1))
			{   
				swap(*ptr, *(ptr + 1));
				swapped = true;
			}
		}
		
		if(swapped == false)
			break;
	}

    cout << endl << "Отсортированный массив: \n";
    for (int *ptr = R; ptr < (R + array_size); ptr++)
    {
        cout << *ptr<< " ";
    }

    return 0;
}

