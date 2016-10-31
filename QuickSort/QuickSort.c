//Implementation of QuickSort
#include <stdio.h>
int* a;
int n;
int Quick(int beg, int end)
{
    int left = beg, right = end, loc = beg;
    int temp;
    while(1)
    {
        //Scan from right to left
        while(a[loc] <= a[right] && loc != right)
            right--;
        if(loc == right)
            return loc;
        if(a[loc] > a[right])
        {
            //Interchange a[loc] and a[right]
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;

            loc = right;
        }

        //Now scanning from left to right
        while(a[loc] >= a[left] && left != loc)
            left++;
        if(loc == left)
            return loc;
        if(a[loc] < a[left])
        {
            //Interchange a[loc] and a[left]
            temp = a[loc];
            a[loc] = a[left];
            a[left] = temp;

            loc = left;
        }
    }
}

void QuickSort()
{
    int beg, end, loc;
    int top = -1;
    int upper[20], lower[20];
    if(n > 1)
    {
        top++;
        lower[0] = 0;
        upper[0] = n-1;
        while(top >= 0)
        {
            beg = lower[top];
            end = upper[top];
            top--;
            loc = Quick(beg, end);

            //Push left sub-list onto stacks when it has 2 or more elements
            if(beg < loc-1)
            {
                top++;
                lower[top] = beg;
                upper[top] = loc - 1;
            }

            //Push right sub-list onto stacks when it has 2 or more elements
            if(loc + 1 < end)
            {
                top++;
                lower[top] = loc + 1;
                upper[top] = end;
            }
        }
    }
}
int main()
{
    int i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    a = malloc(n * sizeof(*a));
    printf("Enter array elements :-\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);

    QuickSort();

    //Displaying the sorted array
    printf("The sorted array is :-\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);

    return 0;
}
