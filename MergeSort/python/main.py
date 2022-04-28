def merge(array,L,R):
    i = j = k = 0
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        array[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        array[k] = R[j]
        j += 1
        k += 1
    return

def mergesort(array):
    if len(array) <= 1:
        return
    else:
        mid = len(array) // 2
        L = array[:mid]
        R = array[mid:]
        mergesort(L)
        mergesort(R)
        merge(array,L,R)
        return
if __name__=="__main__":
  size = int(input("Enter size of array/list : "))
  array = list(map(int, input("Enter multiple values: ").split()))
  mergesort(array)
  print(array)
  #ArTaZ-MergeSort implementation // april 28 , 2022 // Python
