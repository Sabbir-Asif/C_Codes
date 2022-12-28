#include<iostream>
using namespace std;
#define inf 1000000

int find(char arr[], int N, char x)
{
    for(int i = 1; i <= N ; i++)
    {
        if(x == arr[i])
        return i;
    }

    return -1;
}

int main()
{
    int max, edges;
    cout << "How many points : ";
    cin >> max;
    char point[max+1];
    cout << " Enter the points : ";
    for(int i = 1 ; i <= max ; i++)
    {
        cin >> point[i];
    }

    int sieve[max+1][max+1];

    for(int i = 0; i <= max ; i++)
    {
        for(int j = 0 ; j <= max ; j++)
        {
            sieve[i][j] = inf;
        }
    }

    cout << "Enter how many edges : ";
    cin >> edges;
    cout << "Enter the edges : " << endl;
    for(int i = 1 ; i <= edges; i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        sieve[x][y] = sieve[y][x] = w;
    }

    char x;
    int start, finish;
    cout << "Enter starting node : ";
    cin >> x;
    start = find(point, max, x);
    cout << "Enter destination node : ";
    cin >> x;
    finish = find(point, max, x);

    cout << start << " " << finish << endl;

    for(int i = 1 ; i <= max ; i++)
    {
        for(int j = 1 ; j <= max ; j++)
        {
            cout << sieve[i][j] << " ";
        }
        cout << endl;
    }

    int visited[max+1][max+1];
    for(int i = 0 ; i <= max; i++)
    {
        for(int j = 0 ; j <= max; j++)
        {
            visited[i][j] = 0;
        }
    }

    int cur = start;
    cout << start << " ";

    while(cur != finish)
    {
        int cmp = inf;
        int min = inf;
        for(int i = 1; i <= max ; i++)
        {
            if(sieve[cur][i] < cmp)
            {
                cmp = sieve[cur][i];
                min = i;
            }
        }

        if(min == inf)
        {
            cout << "There is no path ahead!" << endl;
            break;
        }
        else if(!visited[cur][min])
        {
            cout << min << " ";
            visited[cur][min] = visited[min][cur] = 1;
            cur = min;
        }
        else
        {
            sieve[cur][min] = sieve[min][cur] = inf;
        }
    }

    return 0;
}