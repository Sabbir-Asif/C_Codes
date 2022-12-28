#include<iostream>
using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int max;
    cout << "Enter number of jobs : " << endl;
    cin >> max;
    int start[max];
    int finish[max];
    string name[max];
    
    for(int i = 0 ; i < max ; i++)
    {
        cout << "Description of the " << i+1 << "th job : ";
        cin >> name[i];
        cout << "Starting time of the " << i+1 << "th job : ";
        cin >> start[i];
        cout << "Finishing time of the " << i+1 << "th job : ";
        cin >> finish[i];
    }
    
    for(int i = 0 ; i < max ; i++)
    {
        for(int j = 0 ; j < max-i-1 ; j++)
        {
            if(finish[j] > finish[j+1])
            {
                swap(finish[j], finish[j+1]);
                swap(start[j],start[j+1]);
                swap(name[j], name[j+1]);
            }
        }
    }

    cout << endl;
    for(int i = 0 ; i < max ; i++)
    {
        if(start[i] != -1)
        {
            for(int j = i+1 ; j < max ; j++)
            {
                if(start[j] < finish[i])
                {
                    start[j] = -1;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0 ; i < max ; i++)
    {
        if(start[i] != -1) count++;
    }
    cout << "You can perform " << count << "job." << endl;
   
    cout << "Sequence of the job : " << endl;
    for(int i = 0 ; i < max ; i++)
    {
        if(start[i] != -1)
        {
            cout << i+1 << " : " << name[i] << "." << endl;
        }
    }
    cout << endl;
    
}