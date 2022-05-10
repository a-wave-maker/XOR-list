# XOR-list
My implementation of a XOR list in C++

It was a project for university and now it's here.

#

A XOR linked list is a doubly linked list that takes the advantage of the XOR operation to save memory. In it the address of a node is a bitwise XOR of the addresses of the next and previous node. 

Instructions:
(# means a number)
ADD_BEG # - add a number to the beginning of the list
ADD_END # - add a number to the end of the list
ADD_ACT # - add a number behind the <a name="act">ACTUAL</a> node
DEL_BEG - remove the first node from the list
DEL_END - remove the last node from the list
DEL_VAL # - delete all nodes with value equal to #
DEL_ACT - delete the <a name="act">ACTUAL</a> node. Set the <a name="prev">PREV</a> node to be <a name="act">ACTUAL</a>
<a name="next">NEXT</a> - print the <a name="next">NEXT</a> node. Set that node to be <a name="act">ACTUAL</a>
<a name="prev">PREV</a> - print the <a name="prev">PREV</a> node. Set that node to be <a name="act">ACTUAL</a>
<a name="act">ACTUAL</a> - print the value of <a name="act">ACTUAL</a> node
PRINT_FORWARD - print the list
PRINT_BACKWARD - print the list backwards
QUIT - end the program


<a name="act">ACTUAL</a> node is the last node added to the list
<a name="prev">PREV</a> node is the node preceding <a name="act">ACTUAL</a>
<a name="next">NEXT</a> node is the node subsequent to <a name="act">ACTUAL</a>