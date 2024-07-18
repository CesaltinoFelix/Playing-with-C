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
Book *copy_book(Book *book)
{
    return (create_book(book->title, book->pages, book->price));
}

Student *create_student(char *name, int age, Book *book)
{
    Student *student = (Student *)malloc(sizeof(Student));
    
    ft_strcpy(student->name ,name);
    student->fav_book = copy_book(book);
    student->age = age;

    return (student);
}

void destroy_book(Book **book)
{
    free(*book);
    *book = NULL;
} 

void destroy_student(Student **student)
{
    destroy_book(&(*student)->fav_book);
    free(*student);
    *student = NULL;
}

void print_book(Book *book)
{
    ft_printf("\tBOOK INFORMATION:\n");
    ft_printf("\t-----------------------\n");
    ft_printf("\t\tTitle: %s\n\t\tPages: %d\n\t\tPrice %d\n", book->title, book->pages, book->price);
}

void print_student(Student *student)
{
    ft_printf("STUDENT INFORMATION:\n");
    ft_printf("-----------------------\n");
    ft_printf("Name: %s\nAge: %d\n", student->name, student->age);
    print_book(student->fav_book);

}


int main(void)
{
    Book *book = create_book("A era do gelo", 200, 1999);
    Student *student = create_student("Cesaltino Felix", 24, book);
    
    print_student(student);

    destroy_student(&student);
    destroy_book(&book);    
}
