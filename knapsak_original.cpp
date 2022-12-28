#include<iostream>
using namespace std;

struct User{
    int weight;
    int value;
};

bool cmp(struct User a, struct User b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

void merge(User arr[], int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  User L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (cmp(L[i], M[j])) {
      arr[k].value = L[i].value;
      arr[k].weight = L[i].weight;
      i++;
    } else {
      arr[k].value = M[i].value;
      arr[k].weight = M[i].weight;
      j++;
    }
    k++;
  }

  while (i < n1) {
   arr[k].value = L[i].value;
      arr[k].weight = L[i].weight;
    i++;
    k++;
  }

  while (j < n2) {
    arr[k].value = M[i].value;
      arr[k].weight = M[i].weight;
    j++;
    k++;
  }
}

void mergeSort(User arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

double knapsack(User arr[], int cap, int item)
{
    mergeSort(arr, 0, item-1);
 
    double finalvalue = 0.0;
 
    for (int i = 0; i < item; i++) {
         
        if (arr[i].weight <= cap) {
            cap -= arr[i].weight;
            finalvalue += arr[i].value;
            cout << "Item added 100% in the bag ";
            cout << "remaining space " << cap << "unit." << endl;
        }

        else {
            finalvalue
                += arr[i].value
                   * ((double)cap / (double)arr[i].weight);
            int p = (int) (((double)cap / (double)arr[i].weight) * 100);
            cout << "Item added " << p << "% in the bag ";
            cout << "remaining space 0 unit." << endl;
            break;
        }
    }
 
    return finalvalue;
}

int main()
{
    int cap, item;
    cout << "Enter the capasity : ";
    cin >> cap;
    cout << "Enter the number of items : ";
    cin >> item;

    User product[item];

    for(int i = 0 ; i < item ; i++)
    {
        cout << "Weight of the  " << i+1 << "th item : ";
        cin >> product[i].weight;
        cout << "Value of the " << i+1 << "th item : ";
        cin >> product[i].value;
    }

    double finalValue = knapsack(product, cap, item);
    cout << "Total value : " << finalValue << endl;

    return 0;
}