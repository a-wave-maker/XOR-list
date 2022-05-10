# XOR-list
My implementation of a XOR list in C++ using object oriented programming.

It was a project for university and now it's here.

#

A XOR linked list is a doubly linked list that takes the advantage of the XOR operation to save memory. In it the address of a node is a bitwise XOR of the addresses of the next and previous node. 

Instructions:
(# means a number)
ADD_BEG # - add a number to the beginning of the list
ADD_END # - add a number to the end of the list
ADD_ACT # - add a number behind the ACTUAL* node
DEL_BEG - remove the first node from the list
DEL_END - remove the last node from the list
DEL_VAL # - delete all nodes with value equal to #
DEL_ACT - delete the ACTUAL node. Set the PREV** node to be ACTUAL
NEXT - print the NEXT** node. Set that node to be ACTUAL
PREV - print the PREV node. Set that node to be ACTUAL
ACTUAL - print the value of ACTUAL node
PRINT_FORWARD - print the list
PRINT_BACKWARD - print the list backwards
QUIT - end the program


*ACTUAL node is the last node added to the list
**PREV node is the node preceding ACTUAL
***NEXT node is the node subsequent to ACTUAL