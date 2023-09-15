Name: Tarang Patel
Student #: 101249181
Files:

Location: Location class, implementation with functions to set/get coordinates, calculate distance between locations, and print street name based on coordinates. It also includes a destructor to free memory.

Order: Order class, which sets and gets an order's information, and prints the customer name associated with the order. It also has a destructor to free memory used by a Location object.

Queue: Queue class that stores orders in a linked list and has operations to add, remove, and retrieve orders as well as to calculate the queue's size and check whether it is empty.

Entity: the Entity class, which has functions for managing orders, setting and getting location, and checking for matching ID.

Franchise:Franchise class that inherits from Entity and adds features for franchises. It has constructors for name and location or just name, getters for location and menu, and print functions for franchise info and menu.


Driver: Driver class which represents a driver that delivers orders. It has constructors for name and location, functions to check if the driver is free and print their information.

Pierres: pierres class which includes member functions to manage drivers, franchises, orders, and drivers pickups. The destructor frees the memory.






compilation: open the terminal in the directory and type "make a3" it should compile all the files and make an executable called "a3". Assuming that you are in the same directory do "./a3".