# include "iostream"
using namespace std;

//template <class, T>
int Binary_search( const int vector[] , int value)
{
    //T* low = vector[0];
    //T* high = sizeof(vetor) / sizeof(vetor)+vector[0]-1;
    int low = 0;
    int high = sizeof(vector) / sizeof(vector[0])-1
    cout << "vector:" << sizeof(vector) << endl;
    cout<<";vector[0]:" << sizeof(vector[0]) << endl;
    cout << "high:" << high << endl;
    //T *middle = (low + high) / 2;
    int middle;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (vector[middle] > value)
        {
            high = middle - 1;
        }
        if (vector[middle] < value)
        {
            low = middle + 1;
        }
        if (vector[middle] == value)
        {
            return middle;
        }
    }
}
int main()
{
    const int a[] = { 1, 2, 5, 8, 13, 19, 25, 38, 40, 47, 69, 48, 90 };
    cout <<"a:" <<sizeof(a) << endl;
    cout<<Binary_search(a, 5)<<endl;
    system("pause");
    return 0;
}
