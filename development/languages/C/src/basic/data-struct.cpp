// C/C++ arrays allow you to define variables that combine several data items of the same kind,
// but structure is another user defined data type which allows you to combine data items of different kinds.

// struct [structure tag] {
//    member definition;
//    ...
// } [one or more structure variables];
// To access any member of a structure, we use the member access operator (.).

#include <iostream>

using namespace std;
void printBook(struct Books book);
void printBookPointer( struct Books *book);

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

typedef struct {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} BooksWithTypeDef;

typedef long long *pint64;

void printBook( struct Books book );

int main()
{
    BooksWithTypeDef booksWithTypeDef;
    strcpy(booksWithTypeDef.title, "C++ programming");
    cout << "BooksWithTypeDef: " << booksWithTypeDef.title << endl;
    long long test = 33;
    pint64 longlongWithTypeDef = &test;
    cout << "longlongWithTypeDef: " << *longlongWithTypeDef << endl;


    struct Books Book1; // Declare Book1 of type Book
    struct Books Book2; // Declare Book2 of type Book

    // book 1 specification
    strcpy(Book1.title, "Learn C++ Programming");
    strcpy(Book1.author, "Chand Miyan");
    strcpy(Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;

    // book 2 specification
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Yakit Singha");
    strcpy(Book2.subject, "Telecom");
    Book2.book_id = 6495700;

    printBook(Book1);
    printBook(Book2);

    printBookPointer(&Book1);
    printBookPointer(&Book2);

    return 0;
}

void printBook( struct Books book ) {
   cout << "Book title : " << book.title <<endl;
   cout << "Book author : " << book.author <<endl;
   cout << "Book subject : " << book.subject <<endl;
   cout << "Book id : " << book.book_id <<endl;
}

void printBookPointer( struct Books *book ) {
   cout << "Book title : " << book->title <<endl;
   cout << "Book author : " << book->author <<endl;
   cout << "Book subject : " << book->subject <<endl;
   cout << "Book id : " << book->book_id <<endl;
}