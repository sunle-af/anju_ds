So first question is how to find the kth smallest element in the array
let say we have an input like this 47292 and say find the 3 smallest element so how we solve is easiest way to solve is 
first sort it then eventually the third element will be the third smallest element 
22479 is the sorted array and at the 3rd element is 4 so that is the answer 
for that we use merge sort now using merge sort will give us the time complexity O(Nlog N)
Now what is the better approach 
pro tip if we hear things like largest of the smallest use data structure called as HEAP they are really good for this
either min heap or max heap or min heap (read aboout it )
if we use max heap you use O(N +k log N ) ki is for poping after we pop element we need to heapify for each each step and taking k element
and the N is used for building an array
Let say a use use min heap then the time complexity will be O(N+(n-k+1)log (N-k+1))
algo is 
first create a method called a kthsmallest which have size of the array and array and number k 
inside it -->will take O(n)
firstly create the mean-heap by taking the array and the size of it-->o(klogn)
apply the extract min to k-1 times and lastly the kth smallest number at the root
total complexity will be O(nlog n)
let say an input given is 
10 1 2 7 25 11 14
so after creating the min-heap 
we have 
            10
        1       2
    7       25 11   14

now modifiactaion 1 will be at the root 
watch video from kthsmallest element |mean heapp approach form  nishank garg 
https://youtu.be/eH7QM6Vb_9I