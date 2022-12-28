#include<iostream>
#define inf 100000
using namespace std;

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
    int max, paths;
    cout << "How many points : ";
    cin >> max;
    char point[max+1];
    cout << "Enter how many edges : ";
    cin >> paths;

    cout << " Enter the points : ";
    for(int i = 1 ; i <= max ; i++)
    {
        cin >> point[i];
    }
    char x;
    int start, finish;
    cout << "Enter starting node : ";
    cin >> x;
    start = find(point, max, x);
    cout << "Enter destination node : ";
    cin >> x;
    finish = find(point, max, x);
    
    cout << start << " " << finish;  //printing starting and finishing time to debug
    
    int sieve[max+1][max+1];
    int visited[max+1][max+1];
    
    for(int i = 1 ; i <= max ; i++)
    {
        for(int j = 1; j <=max ; j++)
        {
            sieve[i][j] = inf;
            visited[i][j] = 0;
        }
    }

    cout << "Enter the edges : ";
    for(int i = 1 ; i <= paths ; i++)
    {
        int x,y, w;
        cin >> x >> y >> w;
        sieve[x][y] = w;
        sieve[y][x] = w;
    }

// Printing the matrix
    for(int i =1 ; i <=max; i++)
    {
    for(int j = 1; j <= max ; j++)
    {
        cout << sieve[i][j] << " ";
    }
      cout << endl;
    }
// Printing ends here

    int head = -1;
    int map[max+1];
    int cur = start;
    while(cur != finish)
    {
        int min = inf;
        for(int i = 1 ; i <= max ; i++)
        {
            if(sieve[cur][i] < min) 
            min = i;
        }

        if(!visited[cur][min]) 
        visited[cur][min] = 1;
        else
        break;
        //head++;
        //map[head] = min;
        cur = min;
        cout << cur << " ";
    }

   /* cout << start << " ";
    for(int i = 0 ; i<=head ; i++)
    {
        cout << map[i] << " ";
    }*/
    cout << endl;

}