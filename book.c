#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_STATUS 10

// Structure definition
struct Book {
    int Book_ID;
    char Title[MAX_TITLE];
    char Author[MAX_AUTHOR];
    float Price;
    char Availability_Status[MAX_STATUS];
};

// Global variables
struct Book *books = NULL;
int N = 0;

// Function prototypes
void create();
void display();
void search();
void issueBook();
void returnBook();

void create() {
    int i;

    printf("\nEnter number of books: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid number of books.\n");
        N = 0;
        return;
    }

    // Dynamically allocate memory
    books = (struct Book *)malloc(N * sizeof(struct Book));

    if (books == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Read book details
    for (i = 0; i < N; i++) {
        printf("\n--- Enter details of Book %d ---\n", i + 1);

        printf("Book ID: ");
        scanf("%d", &books[i].Book_ID);

        printf("Title: ");
        scanf(" %[^\n]", books[i].Title);

        printf("Author: ");
        scanf(" %[^\n]", books[i].Author);

        printf("Price: ");
        scanf("%f", &books[i].Price);

        // Initially every newly added book is available
        strcpy(books[i].Availability_Status, "Available");
    }

    printf("\nBooks created successfully!\n");
}

void display() {
    int i, found = 0;

    if (books == NULL) {
        printf("\nNo book records available.\n");
        return;
    }

    printf("\n========== AVAILABLE BOOKS ==========\n");

    for (i = 0; i < N; i++) {
        if (strcmp(books[i].Availability_Status, "Available") == 0) {
            printf("\nBook ID       : %d", books[i].Book_ID);
            printf("\nTitle         : %s", books[i].Title);
            printf("\nAuthor        : %s", books[i].Author);
            printf("\nPrice         : %.2f", books[i].Price);
            printf("\nStatus        : %s\n", books[i].Availability_Status);

            found = 1;
        }
    }

    if (!found) {
        printf("No books are currently available.\n");
    }
}

void search() {
    int id, i, found = 0;

    if (books == NULL) {
        printf("\nNo book records available.\n");
        return;
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++) {
        if (books[i].Book_ID == id) {
            printf("\n========== BOOK DETAILS ==========\n");
            printf("Book ID       : %d\n", books[i].Book_ID);
            printf("Title         : %s\n", books[i].Title);
            printf("Author        : %s\n", books[i].Author);
            printf("Price         : %.2f\n", books[i].Price);
            printf("Status        : %s\n", books[i].Availability_Status);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void issueBook() {
    int id, i, found = 0;

    if (books == NULL) {
        printf("\nNo book records available.\n");
        return;
    }

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++) {
        if (books[i].Book_ID == id) {
            found = 1;

            if (strcmp(books[i].Availability_Status, "Available") == 0) {
                strcpy(books[i].Availability_Status, "Issued");
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is already issued.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void returnBook() {
    int id, i, found = 0;

    if (books == NULL) {
        printf("\nNo book records available.\n");
        return;
    }

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < N; i++) {
        if (books[i].Book_ID == id) {
            found = 1;

            if (strcmp(books[i].Availability_Status, "Issued") == 0) {
                strcpy(books[i].Availability_Status, "Available");
                printf("\nBook returned successfully!\n");
            } else {
                printf("\nBook is not currently issued.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    do {
        printf("\n\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Book Records\n");
        printf("2. Display All Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("===============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("\nExiting program...\n");

                // Free dynamically allocated memory
                free(books);
                books = NULL;

                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}