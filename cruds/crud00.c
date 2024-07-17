#include "libft.h"

typedef struct _book
{
    char title[50];
    int pages;
    int price;
} Book;

typedef struct _student
{
    char name[100];
    unsigned int age;
    Book *fav_book;
} Student;

Book *create_book(char *title, unsigned int pages, int price)
{
    Book *new_book = (Book *)malloc(sizeof(Book));
    if(!new_book)
        return (NULL);
    ft_strcpy(new_book->title, title);
    new_book->pages = pages;
    new_book->price = price;

    return (new_book);
}

Student *create_student(char *name, int age, Book *book)
{
    (void)name;
    (void)age;
    (void)book;

    return (NULL);
}

void destroy_book(Book **book)
{
    free(*book);
    *book = NULL;
}

void print_book(Book *book)
{
    ft_printf("BOOK INFORMATION:\n");
    ft_printf("-----------------------\n");
    ft_printf("Title: %s\nPages: %d\nPrice %d\n", book->title, book->pages, book->price);
}
int main(void)
{
    Book *book = create_book("A era do gelo", 200, 1999);
    Student *student = create_student("Cesaltino Felix", 24, book);
    
    print_book(book);

    destroy_book(&book);    
}