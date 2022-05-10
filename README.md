# XOR-list
## My implementation of a XOR list in C++. It was a project for university and now it's here.

### A XOR linked list is a doubly linked list that takes the advantage of the XOR operation to save memory. In it the address of a node is a bitwise XOR of the addresses of the next and previous node. 

Instructions:
(# means a number)
ADD_BEG # - add a number to the beginning of the list<br />
ADD_END # - add a number to the end of the list<br />
ADD_ACT # - add a number behind the [ACTUAL](#act) node<br />
DEL_BEG - remove the first node from the list<br />
DEL_END - remove the last node from the list<br />
DEL_VAL # - delete all nodes with value equal to #<br />
DEL_ACT - delete the [ACTUAL](#act) node. Set the [PREV](#prev) node to be [ACTUAL](#act)<br />
[NEXT](#next) - print the [NEXT](#next) node. Set that node to be [ACTUAL](#act)<br />
[PREV](#prev) - print the [PREV](#prev) node. Set that node to be [ACTUAL](#act)<br />
[ACTUAL](#act) - print the value of [ACTUAL](#act) node<br />
PRINT_FORWARD - print the list<br />
PRINT_BACKWARD - print the list backwards<br />
QUIT - end the program<br />


<a name="act">ACTUAL</a> node is the last node added to the list<br />
<a name="prev">PREV</a> node is the node preceding [ACTUAL](#act)<br />
<a name="next">NEXT</a> node is the node subsequent to [ACTUAL](#act)