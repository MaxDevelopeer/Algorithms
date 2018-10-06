using namespace std;
    template<class T>
       vector <T> sort(vector<T> const &input)
       {
            vector <T> output=input;
            for (int j=1;j<output.size();j++)
            {
              int i=j;
              while (i>0 && output[i-1]>output[i])
                {
                  swap(output[i],output[i-1]);
                  i--;
                }
            }
          return output;
      };
