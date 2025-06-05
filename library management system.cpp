#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook() {
    FILE *fp = fopen("books.dat", "ab");
    struct Book book;

    printf("\nEnter Book ID: ");
    scanf("%d", &book.id);
    getchar();
    printf("Enter Book Title: ");
    fgets(book.title, 50, stdin);
    printf("Enter Book Author: ");
    fgets(book.author, 50, stdin);

    fwrite(&book, sizeof(book), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen("books.dat", "rb");
    struct Book book;

    printf("\nAll Books:\n");
    while (fread(&book, sizeof(book), 1, fp)) {
        printf("ID: %d\nTitle: %sAuthor: %s\n", book.id, book.title, book.author);
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("books.dat", "rb");
    struct Book book;
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(book), 1, fp)) {
        if (book.id == id) {
            printf("Book Found!\nTitle: %sAuthor: %s\n", book.title, book.author);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

void deleteBook() {
    FILE *fp = fopen("books.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Book book;
    int id, found = 0;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(book), 1, fp)) {
        if (book.id != id) {
            fwrite(&book, sizeof(book), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat", "books.dat");

    if (found)
        printf("Book deleted successfully.\n");
    else
        printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Library Menu =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

