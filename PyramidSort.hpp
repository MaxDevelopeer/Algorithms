size_t child_left_index (size_t indexElement)  //seach left child index for specified element (counting of elements starts with 0,so we +1)
{
    return (indexElement<<1)+1;
}
size_t child_right_index (size_t indexElement) //seach right child index for specified element (counting of elements starts with 0,so we +2)
{
    return (indexElement<<1)+2;
}


template <class T>
void maintaining_non_increasing_pyramid (vector <T> &inputData, size_t indexElement, size_t sizePyramid)
{
    size_t lchildIndex =child_left_index(indexElement);
    size_t rchildIndex=child_right_index(indexElement);
    size_t indexLargestElement=indexElement;   // index of max element of the three possible: specified element, his left child or right child
    if (lchildIndex<=sizePyramid-1 && inputData[lchildIndex]>inputData[indexElement])
           indexLargestElement=lchildIndex;
    if (rchildIndex<=sizePyramid-1 && inputData[rchildIndex]>inputData[indexLargestElement])
           indexLargestElement=rchildIndex;
    if (indexLargestElement!=indexElement)  // recursively called function which swaps elements that  violate the rule of non-growth
        {
           swap (inputData[indexElement],inputData[indexLargestElement]);
           maintaining_non_increasing_pyramid(inputData, indexLargestElement, sizePyramid); // recursively called on this string

        }
}

template <class T>
void build_non_increasing_pyramid (vector <T> & inputData)
{
    for (int step=inputData.size()/2-1;step>=0;step--)
    {
        maintaining_non_increasing_pyramid(inputData, step, inputData.size());
    }
}

template <class T>
void pyramid_sort (vector <T> &inputData)   // main sorting function
{
    size_t sizePyramid=inputData.size();
    build_non_increasing_pyramid(inputData);
    for (size_t step=inputData.size()-1;step>=1;step--)
    {
        swap (inputData[0],inputData[step]);
        sizePyramid--;
        maintaining_non_increasing_pyramid(inputData, 0, sizePyramid);

    }
}

template <class T>
vector <T> pyramid_sort_const (vector <T> const  &inputData)
{
    vector <T> subsidiaryData(inputData);
    pyramid_sort(subsidiaryData);
    return subsidiaryData;
}
