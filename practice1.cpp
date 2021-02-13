#include <iostream>

using namespace std;

void print_array(int* array, int length_of_array)
{
    // Выведет массив
    cout << endl;
    cout << "Массив: ";

    for (int i = 0; i < length_of_array; i++)
        cout << array[i] << ", ";
    cout <<endl;
}


int length_of_array()
{   
    // Запись длины массива
    int number;
    cout << "Enter a length of array: ";
    cin >> number;
    return number;
}


void create_array(int* array ,int size)
{
    // Заполнение массива
    for (int i = 0; i < size; i ++)
        array[i] = rand() % 100;
}


int average_element_of_array(int* array, int size_of_array)
{
    // Среднее арифметическое массива
    int average;
    int sum = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        sum = sum + array[i];
    }
    average = sum / size_of_array;

    return average;
}


int max_element_of_array(int* array, int size_of_array)
{
    // Номер максимального элемента массива
    int number_max = 0;
    int handler = 0;

    for (int i = 0; i < size_of_array; i++)
    {
        if (array[i] > handler)
        {
            handler = array[i];
            number_max = i;
        }
    }

    return number_max;
}


bool prime_element(int element)
{
    // Проверяет простое ли число
    if (element > 1)    
    {
        for (int i = 2; i < element; i++)
        {
            if (element % i == 0)
                return false;
        }
        return true;
    }
    else
        return false;
}


int count_prime_element(int* array, int length_of_array)
{
    // Количество простых чисел
    // Нужно чтобы позже сократить массив на это количество
    int counter = 1;
    for (int i = 0; i < length_of_array; i++)
    {
        if (prime_element(array[i]))
            counter++;
    }
    return counter;
}


int* deleted_prime_array(int* array, int number_max_element, int length_of_array)
{
    // Тот же самый массив но с удалёнными простыми числами
    for (int i = 0; i < length_of_array; i++)
    {
        if (i > number_max_element)
        {
            if (prime_element(array[i]))
            {
                for (int index = i; index < length_of_array + 1; ++index)
                    array[index] = array[index + 1];
                
                --length_of_array;
            }
        }
       
    }

    return array;
}


int main()
{
    // создание массива
    int size_of_array = length_of_array();
    int *array = new int[size_of_array];
    create_array(array, size_of_array);
    print_array(array, size_of_array);

    // среднее арифметическое массива
    int average_element = average_element_of_array(array, size_of_array);

    // номер максимального элемента массива
    int max_element = max_element_of_array(array, size_of_array);

    // вывод
    cout << "Среднее арифметическое: " << average_element << endl;
    cout << "Номер максимального элемента массива: " << max_element << endl;    


    // новый массив с удаленными простыми числами после максимального числа
    int* new_array = deleted_prime_array(array, max_element, size_of_array);
    int new_size_of_array = size_of_array - count_prime_element(array, size_of_array);
    print_array(new_array, new_size_of_array);

    int new_average_element = average_element_of_array(array, new_size_of_array);
    
    cout << "Новое среднее арифметическое: " << new_average_element << endl;

    // Удаление элементов
    delete[] array;

    return 0;
}

