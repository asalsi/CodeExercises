#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int size = 6;
// int arr[][4] = {{1, 2, 3, 4},
//                 {12,13,14,5},
//                 {11,16,15,6},
//                 {10, 9, 8,7}};

// int arr[][5] = {{1, 2, 3, 4, 5},
//                 {16,17,18,19,6},
//                 {15,24,25,20,7},
//                 {14,23,22,21,8},
//                 {13,12,11,10,9}};

int arr[][6] = {{1, 2, 3, 4, 5, 6},
                {20,21,22,23,24,7},
                {19,32,33,34,25, 8},
                {18,31,36,35,26, 9},
                {17,30,29,28,27,10},
                {16,15,14,13,12,11}};

int* spiralTraverse(int* result, int shift, int cons, int bound, int i, int c_i, bool flip, bool op, int s_bound)
{
    // Assing index order
    int row, col;
    row = shift;
    col = cons; // MBNA!
    if (flip)
    {
        row = cons;
        col = shift;
    }

    // base case
    if (i == size*size)
    {
        return result;
    }

    // add to result
    result[i] = arr[row][col];

    printf("shift %i: %i\n", i, shift);
    /* 
        bounds, direction for next layer 
    */
    int new_shift = shift;

    // if @ a bound (right corner)
    if (shift == bound)
    {
        printf("> CORNER HIT\n");

        c_i++;
        flip = !flip;

        new_shift = cons;
        cons = shift;

        // TL or BR
        if (c_i%2 == 0)
        {
            
            op = !op;
            printf("> OPERATION SWITCHED\n");

            if (i < size / 2)
            {
                // bound = size - bound - 1; // 4 - 3 - 1
                bound = size - bound;
            }
            else
            {
                bound = size - bound - s_bound - 1; // 4 - 3 - 1
            }
            // 5 , 0
            // 4, 1
            // 3, 2

        }

        // bottom left
        if (c_i%3 == 0)
        {
            s_bound += 1;
            bound = s_bound; // relative index?
            // lucky for sizes 4 and 5

        }
    }

    if (op)
    {
        shift = new_shift + 1;
    }
    else if (!op)
    {
        shift = new_shift - 1;
    }

    return spiralTraverse(result, shift, cons, bound, i+1, c_i, flip, op, s_bound);
}



int main(void)
{
    int* result = malloc(size * size); 
    result = spiralTraverse(result, 0, 0, size - 1, 0, 0, true, true, 0);

    for (int i = 0, n = size * size; i < n; i++)
    {
        printf("%i\n", result[i]);
    }
    printf("\n");

    free(result);

}

// int* spiralTraverse(int* arr, int row, int col, int count)
// {
//     /*
//         returns an array of all the array's element in a spiral order
//     */

//    if (count == size * 4)   // perimeter size
//    {
//         return arr;
//    }
//    // move right across top
//    else if (col < size - 1)
//    {

//        return spiralTraverse(c, row, col + 1, count + 1);
//    }
//    // move down right
//    else if (col == size - 1)
//    {
//     //    c[count] = itoa(arr[row][col]);
//        sprintf(c[count], "%d", n);
//        return spiralTraverse(c, row + 1, col, count + 1);
//    }
//    // move left across bottom
//    else if (row < size - 1)
//    {
//     //    c[count] = itoa(arr[row][col]);
//         sprintf(c[count], "%d", n);
//        return spiralTraverse(c, row, col - 1, count + 1);
//    }
//    // move up across left
//    else if (col == 0 && row != 0)
//    {
//     //    c[count] = itoa(arr[row][col]);
//         sprintf(c[count], "%d", n);
//        return spiralTraverse(c, row - 1, col, count + 1);
//    }
   
// }



// int* spiralTraverse_d(int* result, int size, int i, int j, int r_i, int dist, int count)
// {
//     if (r_i == size*size)
//     {
//         return result;
//     }

//     result[r_i] = arr[i][j];
//     r_i++;

//     // every 2 corners, decrement distance to travel along current direction
//     // if ((r_i - 1)%2 == 0)
//     // {
//     //     dist--;
//     // }

//     // if count along current direction is less than distance to travel
//     // if (count == dist)
//     // {
//     //     count = 0;
//     // }

//     // SWITCHES:
//     // if TR || top l-r
//         // j same
//         // i increment
//     // if BR || right t-b
//         // i same
//         // j decrement
//     // if BL || bottom r-l
//         // j same
//         // i decrement
//     // if TL || left b-t
//         // i same
//         // j increment


//     /* SPECIAL CASES
//         - all corners: reset count
//         - TR, BL: decrement distance to travel
//     */
//     // TR, BL
//     count++;
//     if (i + j == size - 1)
//     {
//         // dist--;
//         // count = 0;
//         // TR
//         if (i < size/2)
//         {
//             // recursive call with count = 0, dist - 1, i = size - dist, j = 
//         }
//         // BL
//         else if (i > size/2)
//         {
//             // recursive call with i = dist, j = 0
//         }
//     }
//     // BR
//     else if ((i == j) && i >= size/2)   // weird for even and odd; testing with even, should be good
//     {
//         count = 0;
//     }
//     // TL
//     else if ((i == j + 1) && i < size/2)    //
//     {
//         count = 0;
//     }

//     /* RECURSIVE CASES 
//         i: use 
//     */

//     // if (i < size)// i is b/w or @ TL - TR)

    
//     /*
//     size = 5


//     5 ->  TR       1        
//     4 v            2        
//     4 <-  BL       3        
//     3 ^            4        

//     3 ->  TR
//     2 v
//     2 <-  BL
//     1 ^

//     1 ->  TR

//     r-l top
//     t-b right
//     l-r bottom
//     b-t left

//     */


    
// }