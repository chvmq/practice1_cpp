#include <iostream>
#include <cmath>

using namespace std;

void DeleteElement(int* arr, int length, int pos) {
 
    for( ; pos < length - 1; ++pos) arr[pos] = arr[pos + 1];
}
 
bool IsPrime(int num) {
 
    if(2 == num) return true;
    if(!(num%2)) return false;
 
    for(int i = 2; i <= sqrt((double)num); ++i) {
        if(!(num%i)) return false;
    }
 
    return true;
}

void print_array(int* array, int length_of_array)
{
    // Выведет массив
    cout << endl;
    cout << "Массив: ";

    for (int i = 0; i < length_of_array; i++)
        cout << array[i] << ", ";
    cout <<endl;
}

void fill_array(int* array, int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
        array[i] = 1 + rand() % 100;
}

int set_length_of_array()
{
    int number;
    cout << "размер массива: ";
    cin >> number;
    return number;
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

void standart_output(int average, int max_element)
{
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Номер максимального элемента массива: " << max_element << endl; 
}
 
int main() {
 
    int length_of_array = set_length_of_array();
    int *arr = new int[length_of_array];

    fill_array(arr, length_of_array);
    print_array(arr, length_of_array);

    int average = average_element_of_array(arr, length_of_array);
    int max_element = max_element_of_array(arr, length_of_array);

    standart_output(average, max_element);

    for (int i = 0; i < length_of_array; i++)
    {
        if (i > max_element)
            if (IsPrime(arr[i]))
            {
                DeleteElement(arr, length_of_array, i);
                length_of_array--;
            }
    }

    print_array(arr, length_of_array);

    int new_average = average_element_of_array(arr, length_of_array);
    int new_max_element = max_element_of_array(arr, length_of_array);
    
    standart_output(new_average, new_max_element);

    delete [] arr; 
    return 0;
}
