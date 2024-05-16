# A1: Learning Array Data structure and its application

Design the algorithm and implement in Java.  
1.	Write a function for linearsearch(a[1..n],start,data) that searches for data in a starting from position start. Let the function return the position of data if found; -1 otherwise.
2.	Write a function for insertmiddle(a[1..n], data,after) that inserts data at position after+1.
3.	Use these functions to implement insertafterdata(a[1..n], data1, data2) that inserts data2 after every occurrence of data1 in a. 

Eg. Input:
 a[7]	45	13	25	13	43	25	13
 
 data1 	13
 
 data2	33
 
Output
	45	13	33	25	13	33	43	25	13	33

Step 1 - Accept stream of integers and create instance variable data 1 and data 2 with appropriate value. Resize the array elements by striping last two elements on previous state. 

Step 2 - Implement linearSearch method version 1 - to return list of indices where the element(data1) is found.

