#include <vector>
using namespace std;

    template<class T>
    vector <T> sort(vector<T> const &input)
    {
        vector <T> output(input);
        vector <T>  key(1);
        if (input.size()<2)
        {
            return output;
        }
        for (int j=1;j<output.size();j++)
        {
            key[0]=output[j];
            int i=j-1;
            while (i>=0 && output[i]>key[0])
            {
                output[i+1]=output[i];
                if (i>0)
                {
                    i=i-1;
                    output[i+1]=key[0];
                }
                else
                {
                    output[i]=key[0];
                }
            }
        }
        return output;
    };
