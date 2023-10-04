# Sparse-Array-and-Matrix
## Representing arrays with huge number of zeros(unused space) using a doubly linked list.
- In some applications, we might want to represent an array with indices very huge (e.g. 10^8), however, most of it are just zeros (e.g. 95%).
  
- Creating such huge arrays is very time & memory harmful with no return:
  - Complete: 0 0 20 0 40 50 0 70 0 0.
  - Better: (50, 5), (20, 2), (70, 7), (40, 4) = (value, idx) list.

- A better idea is to represent such arrays using a linked list.

- Create a linked list: ArrayLinkedList:
  - Use a doubly linked list.

- It represents a sparse array. Provide the following functions:
  - Set and Get positions, Print array.

- A useful application: Polynomial representation (e.g. 2X60 + 17X1500). 
