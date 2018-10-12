template <class T>
int partition_data (vector <T> &inputData,int leftBorder, int rightBorder)
{
    vector <T> subsidiaryData(1);
    subsidiaryData[0]=inputData[rightBorder]; // base element
    int indexElement=leftBorder-1;
    for (size_t step=leftBorder;step<rightBorder;step++)
    {
        if (inputData[step]<=subsidiaryData[0])
        {
            indexElement++;
            swap(inputData[step],inputData[indexElement]);
        }
    }
    swap(inputData[rightBorder],inputData[indexElement+1]);
    return indexElement+1;
}

template <class T>
void quick_sort (vector <T> &inputData,int leftBorder, int rightBorder )
{
    if (leftBorder<rightBorder)
    {
        int indexElement=partition_data(inputData, leftBorder, rightBorder);
        quick_sort(inputData, leftBorder, indexElement-1); // recursively called function which sorted elements in 1st half
        quick_sort(inputData, indexElement+1, rightBorder); // in 2nd half
    }
}

template <class T>
vector <T> quick_sort_const (vector <T> const &inputData)
{
    vector <T> subsidiaryData (inputData);
    quick_sort (subsidiaryData,0,subsidiaryData.size()-1);
    return subsidiaryData;
}
