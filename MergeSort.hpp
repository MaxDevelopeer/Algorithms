#include <vector>
using namespace std;
template<class T>

void merge_sort (vector <T> &inputData, size_t leftBorder, size_t rightBorder)
{
    if (leftBorder==rightBorder) // one element difinitely sorted
        return;
    size_t middlePosition=(leftBorder+rightBorder)/2; // find middle of sequence and recursively called function of sort for both halves
    merge_sort(inputData, leftBorder, middlePosition);
    merge_sort(inputData, middlePosition+1, rightBorder);
    size_t startFirstHalf=leftBorder;
    size_t startSecondHalf=middlePosition+1;
    vector <T> subsidiaryData(0);
    for (size_t step = 0; step < rightBorder - leftBorder + 1; step++) // merge cycle
      {

          if ((startSecondHalf > rightBorder) || ((startFirstHalf <= middlePosition) && (inputData[startFirstHalf] < inputData[startSecondHalf])))
          {
              subsidiaryData.push_back(inputData[startFirstHalf]);
              startFirstHalf++;
          }
          else
          {
              subsidiaryData.push_back(inputData[startSecondHalf]);
              startSecondHalf++;
          }
      }
    for (int step = 0; step < rightBorder - leftBorder + 1; step++)  // put the subsidiary data in the original inputData
          inputData[leftBorder + step] = subsidiaryData[step];
}
template<class T>
vector<T> merge_sort_const (vector<T> const &inputData)
{
    vector<T> subsidiaryData(inputData);
    merge_sort(subsidiaryData, 0, subsidiaryData.size() - 1);
    return subsidiaryData;

}
