# import sys
# reinvent a wheel
# def pmat(mat):
#     for i in range(len(mat)):
#         for j in range(len(mat)):
#             sys.stdout.write(str(mat2[i][j]) + " ")
#         sys.stdout.write("\n")
#     sys.stdout.write("\n")

### a change

### another change

# call recursive function, join result to single list
def spiralTraverse(mat):
    lst = spiral_recurse(mat, [])
    concat_lst = [j for i in lst for j in i]
    return concat_lst

# unwind 2D matrix into return string, with CW as L-R
def spiral_recurse(mat, lst):
    
    # base case (avoid actually appending middle 4 or one to list for now)
    if (len(mat) is 0): 
        # return ''.join(str(lst))
        return lst

    elif (len(mat) is 1):
        lst.append([mat[0][0]])
        # return ''.join(str(lst))
        return lst
    
    # add perimeter of matrix to list; recursive call
    else:
        # would like cleaner list comprehension
        upper_left = mat[0] + [row[len(mat) - 1] for row in mat[1:len(mat) - 1]]
        lower_right = [row[0] for row in mat[1:len(mat) - 1]] + mat[len(mat) - 1]
        lower_right.reverse()
        lst.append(upper_left + lower_right)

        return spiral_recurse([row[1:len(mat) - 1] for row in mat[1:len(mat) - 1]], lst)
        
#### TEST CASES
size_5 = [[1, 2, 3, 4, 5],
        [16,17,18,19,6],
        [15,24,25,20,7],
        [14,23,22,21,8],
        [13,12,11,10,9]]

size_6 = [[1, 2, 3, 4, 5, 6],
        [20,21,22,23,24,7],
        [19,32,33,34,25, 8],
        [18,31,36,35,26, 9],
        [17,30,29,28,27,10],
        [16,15,14,13,12,11]]


print("SIZE 5 ************")
size_5 = spiralTraverse(size_5)
print(size_5)
print("")
print("SIZE 6 ************")
size_6 = spiralTraverse(size_6)
print(size_6)




'''
### Getting the perimeter of matrix as a list
upper_left = size_5[0] + [row[len(size_5) - 1] for row in size_5[1:len(size_5) - 1]]
lower_right = [row[0] for row in size_5[1:len(size_5) - 1]] + size_5[len(size_5) - 1]
lower_right.reverse()
print(upper_left + lower_right)

### Grabbing the middle square from matrix
mat2 = [row[1:4] for row in size_5[1:4]]
pmat(mat2)
'''
