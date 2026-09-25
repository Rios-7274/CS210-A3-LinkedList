1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.

    
It takes two separate delete calls because it must delete both the node and Data value that the "T" 
    in the node points to. The new call that allocates memory for the data is in `main.cpp` when addFront 
    is called. The new call that allocates memory for the node is in the addFront method in LinkedList. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?

    
Switching from "T " to "T* ", requires us to add a destructor to arraylist because the values 
    replaces with pointers and pointers utilize Heap memory rather than the stack memory of the value.
    Heap memory does not automatically clear at the end of the program, unlike Stack memory which `ArrayList` 
    previously utilized, a destructor is required to delete the memory while running.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?

   
In linkedlist, search() takes T* and uses it to reach the actual value that `value`, the pointer, points to. 
    In addfront(), the method takes the address of T* to create a new Node in heap to be inserted into
    the list. The node created in addFront() with the handed pointer is able to be deleted completely in 
    deleteFront(), while search() can not delete or change the pointer it receives. LinkedList owns the node 
    created with the T*, and search() can only borrow the address from Main.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?

The two mechanism that make this possible are virtual, that picks the version at run time, 
    and each virtual method is pure virtual (= 0), this means that the body for each method can 
    only come from inheritance with LinkedList or ArrayList.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.

A keyword from the labs glossary that I had to add and learned about while implementing 
    is the `virtual` keyword that prepares the methods for List to choose its version depending on
    exactly what implementation is used for the list. The version specifically belongs to the implementation
    files method of the same name, but without the `virtual` keyword, this choice would never be made while the
    project runs, which leaves the methods for List empty and unusable.
    