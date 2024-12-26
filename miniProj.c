#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure definition
struct Book {
    int id;
    char title[50];
    char author[50];
    int isAvailable;
};

// Function prototypes
void addBook(struct Book books[], int *bookCount);
void displayBooks(const struct Book books[], int bookCount);
void searchBook(const struct Book books[], int bookCount);

int main() {
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                searchBook(books, bookCount);
                break;
            case 4:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a book
void addBook(struct Book books[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &books[*bookCount].id);
    printf("Enter book title: ");
    scanf("%s", books[*bookCount].title);  // Using %s for string input
    printf("Enter author name: ");
    scanf("%s", books[*bookCount].author);  // Using %s for string input

    books[*bookCount].isAvailable = 1;  // Mark the book as available
    (*bookCount)++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks(const struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-30s %-15s\n", "Book ID", "Title", "Author", "Availability");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-30s %-15s\n", books[i].id, books[i].title, books[i].author, 
               books[i].isAvailable ? "Available" : "Not Available");
    }
}

// Function to search for a book by title
void searchBook(const struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    char searchTitle[50];
    printf("Enter the title of the book to search: ");
    scanf("%s", searchTitle);  // Using %s for string input

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book Found!\n");
            printf("ID: %d, Title: %s, Author: %s, Availability: %s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].isAvailable ? "Available" : "Not Available");
            return;
        }
    }
    printf("Book not found.\n");
}
