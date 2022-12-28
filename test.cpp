#include <iostream>
using namespace std;
#define max 10

struct User{
    int weight;
    int value;
};
int main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    struct User product[max]; 

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        cout << "Weight[" << i << "] : ";
        cin >> product[i].weight;
        cout << "Value[" << i << "] : ";
        cin >> product[i].value;
    }

    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) product[i].value / product[i].weight > (float) product[item].value / product[item].weight)))
                item = i;

        used[item] = 1;
        cur_weight -= product[item].weight;
        total_profit += product[item].value;
        if (cur_weight >= 0)
            printf("Added object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, product[item].value, product[item].weight, cur_weight);
        else
        {
            int item_percent = (int) ((1 + (float) cur_weight / product[item].weight) * 100);
            printf("Added %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, product[item].value, product[item].weight, item + 1);
            total_profit -= product[item].value;
            total_profit += (1 + (float)cur_weight / product[item].weight) * product[item].value;
        }
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);
}