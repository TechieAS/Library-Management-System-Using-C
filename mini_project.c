#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct book
{
    char title[100];
    char author[100];
    int isbn;
    bool is_borrowed;
    bool is_return;
};

int main()
{
    int choice1 = 1, choice, count = 0;
    struct book books[100];
    char search[100];

    printf("Welcome to the library\n");

    do
    {
        printf("\nMenu\n");
        printf("Press 1: Add a book\n");
        printf("Press 2: Search for a book\n");
        printf("Press 3: Borrow a book\n");
        printf("Press 4: Return a book\n");
        printf("Press 5: Display all books\n");
        printf("Press 6: Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter book title: ");
            scanf(" %[^\n]", books[count].title);
            printf("Enter author name: ");
            scanf(" %[^\n]", books[count].author);
            printf("Enter book ISBN: ");
            scanf("%d", &books[count].isbn);

            books[count].is_borrowed = false;
            books[count].is_return = true;

            count++;
            printf("Book added successfully.\n");
            break;

        case 2:
            if (count == 0)
            {
                printf("Library is empty.\n");
            }
            else
            {
                printf("Enter book title or author name to search: ");
                scanf(" %[^\n]", search);

                int found = 0;
                for (int i = 0; i < count; i++)
                {
                    if (strcmp(books[i].title, search) == 0 || strcmp(books[i].author, search) == 0)
                    {
                        printf("\nBook found!\nTitle: %s\nAuthor: %s\nISBN: %d\nAvailable: %s\n",
                               books[i].title, books[i].author, books[i].isbn,
                               (books[i].is_borrowed ? "No" : "Yes"));
                        found = 1;
                    }
                }
                if (!found)
                {
                    printf("Book not found.\n");
                }
            }
            break;

        case 3:
            printf("Enter book title to borrow: ");
            scanf(" %[^\n]", search);
            int borrowed = 0;
            for (int i = 0; i < count; i++)
            {
                if (strcmp(books[i].title, search) == 0 && !books[i].is_borrowed)
                {
                    books[i].is_borrowed = true;
                    books[i].is_return = false;
                    printf("Book borrowed successfully.\n");
                    borrowed = 1;
                    break;
                }
            }
            if (!borrowed)
            {
                printf("Book not available.\n");
            }
            break;

        case 4:
            printf("Enter book title to return: ");
            scanf(" %[^\n]", search);
            int returned = 0;
            for (int i = 0; i < count; i++)
            {
                if (strcmp(books[i].title, search) == 0 && books[i].is_borrowed)
                {
                    books[i].is_borrowed = false;
                    books[i].is_return = true;
                    printf("Book returned successfully.\n");
                    returned = 1;
                    break;
                }
            }
            if (!returned)
            {
                printf("Book return failed.\n");
            }
            break;

        case 5:
            if (count == 0)
            {
                printf("Library is empty.\n");
            }
            else
            {
                printf("\nLibrary Books:\n");
                for (int i = 0; i < count; i++)
                {
                    printf("Book %d:\nTitle: %s\nAuthor: %s\nISBN: %d\nAvailable: %s\n",
                           i + 1, books[i].title, books[i].author, books[i].isbn,
                           (books[i].is_borrowed ? "No" : "Yes"));
                }
            }
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue? (Yes=1 / No=2): ");
        scanf("%d", &choice1);

    } while (choice1 == 1);

    return 0;
}