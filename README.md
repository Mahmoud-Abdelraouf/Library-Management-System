# Library Management System Readme

## Introduction

This repository contains the source code for a simple Library Management System implemented in C. The system allows users to manage books in a library by performing various operations such as adding new books, deleting books, viewing all books, and checking the number of available books.

## Features

1. View all books: Users can view the details of all the books available in the library.

2. Add a new book: Users can add a new book to the library by providing the book's name, author's name, and the book's price.

3. Delete a book: Users can remove a book from the library by specifying the book's position.

4. View the number of available books: Users can check the total number of available books in the library.

## Implementation

The library management system is implemented using a linked list data structure to store the information of each book. The main functionalities are organized as follows:

- **`List_t`**: The structure representing the linked list that holds book information.
- **`List_State_t`**: An enumeration representing the state of the linked list (empty or not empty).
- **`CreateList`**: Function to create an empty linked list.
- **`DisplayData`**: Function to display all the books in the library.
- **`AddToBack`**: Function to add a new book to the end of the linked list.
- **`List_Empty`**: Function to check if the linked list is empty or not.
- **`CheckRange`**: Function to check if the position provided is within the valid range of the linked list.
- **`RemoveFromPosition`**: Function to delete a book from the linked list at a specified position.

## Usage

To use the Library Management System, follow these steps:

1. Compile the code using a C compiler (e.g., GCC).
2. Run the executable.
3. The program will display a menu with the available options.
4. Choose the desired option by entering the corresponding number.
5. Follow the on-screen prompts to perform the selected action.
6. To exit the program, choose option 5 from the menu.

## Contributors

The Library Management System was created by Eng. Mahmoud Abdel-Raouf Mahmoud.

## License

The code in this repository is provided under the [MIT License](LICENSE), allowing users to modify and distribute the code as they see fit. However, please note that this system is intended for educational purposes and may not be suitable for production environments without further enhancements and security measures.

## Acknowledgments

Special thanks to all contributors and developers who have contributed to open-source libraries and resources used in building this Library Management System.

---

Please note that this is a basic implementation, and in a real-world scenario, a full-fledged library management system would require additional features, data validation, error handling, and security considerations. Additionally, the code provided here may not be optimal for large-scale libraries, and further optimization might be necessary.
