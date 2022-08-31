#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define AVAILABLEBOOKS 5 // if changed then change in also initialization
typedef struct library
{
    int accession_no;
    char title_of_book[20];
    char author_name[20];
    float price;

} book;
book b[AVAILABLEBOOKS] ={
    102, "Alchemist", "Paulo Coelho", 199.9,
    105, "Rich dad Poor dad", "Robart kiyosaki", 300.0,
    107, "aptitude", "R S Agrawal", 449.9,
    106, "c langauge", "Denice Ritchie", 500.0,
    104, "start with why", "Simon Sinek", 349.9
    };
void display_all_books(book *);                       // for case 1
void store_book_info_in_library(book *, book *, int); // for case 2
void display_added_books(book *, int);                // for case 2
void booksByauthor(book *, book *, char *, int);      // for case 3
void booksBytitle(book *, book *, char *, int);       // for case 4
void sortByaceessonNumber(book *, book *, int);       // for case 5
void sortedbooks(book *, book *, int);                // for case 5
int returnMin(book *, book *, int);

int findmin(book *, book *, int, int *);     // case 6
void showBookInfo(book *, int);              // case 6
int findNext(book *, book *, int, int *);    // case 6
int nextelement(book *, book *, int, int *); // case 6

int i,
    m, flag = 0, smallest, next; // i for index and m for added books to access into all functions
int main()
{
    book *b1 = NULL; /*for case 2*/
    int choice;
    printf("\n\t\t\t\t\t\t\t\tWELCOME TO MY LIBRARY ");
    while (1)
    {
        printf("\n\n=================================================================================");
        printf("\n\n\n\t\t\tEnter the Numbers to access Library  ");
        printf("\n\n\t\t\t\t1.Display all availaible Books in Library");
        printf("\n\t\t\t\t2. Donate some books to library ");
        printf("\n\t\t\t\t3. List all books of given author");
        printf("\n\t\t\t\t4. List the title of specified book");
        printf("\n\t\t\t\t5. List the count of books in the library");
        printf("\n\t\t\t\t6. List the books in the order of accession number");
        printf("\n\t\t\t\t7. Exit");
        printf("\n\n=================================================================================");
        printf("\n\n\n\n\t\t\tPlease Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            display_all_books(b);
            break;
        }
        case 2:
        {
            printf("Enter the Number of books to be donate:");
            scanf("%d", &m);
            b1 = (book *)malloc(m * sizeof(book));
            store_book_info_in_library(b1, b, m);
            display_added_books(b1, m);
            break;
        }
        case 3:
        {
            char Author[20];
            printf("\n\n\t\tEnter the author name to search : ");
            fflush(stdin);
            scanf("%[^\n]s", Author);
            booksByauthor(b, b1, Author, m);
            break;
        }
        case 4:
        {
            char title[20];
            printf("\n\n\t\tEnter the Title of book to search : ");
            fflush(stdin);
            scanf("%[^\n]s", title);
            booksBytitle(b, b1, title, m);
            break;
        }
        case 5:
        {
            printf("\n\n\t\t\t\t\tThere are %d book available in this library.", AVAILABLEBOOKS + m);
            break;
        }
        case 6:
        {
            sortByaceessonNumber(b, b1, m);
            printf("\n\n\t\tAll Books are sorted according to accession number as : \n");
            sortedbooks(b, b1, m);
            break;
        }
        }
    }
    free(b1);
    return 0;
}
void display_all_books(book *b)
{
    for (i = 0; i < AVAILABLEBOOKS; i++)
    {
        printf("\n\tAccession number : %d", b[i].accession_no);
        printf("\n\t\t\t\t\tTitle Of Book : %s", b[i].title_of_book);
        printf("\n\t\t\t\t\tAuthor : %s", b[i].author_name);
        printf("\t\tPrice : %f", b[i].price);
        printf("\n\n");
    }
}
void store_book_info_in_library(book *b1, book *b, int n)
{
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the %dth Book inforamtion:\n", i + 1);
        fflush(stdin);

        printf("\n\tEnter the Accession number :");
        scanf("%d", &b1[i].accession_no);
        int j = 0, k = i - 1;
        while (j < AVAILABLEBOOKS)
        {
            if ((b1[i].accession_no == b[j].accession_no) || (b1[i].accession_no == b1[k].accession_no))
            {
                printf("Accession slot Not available.Please Enter another one");
                printf("\n\tEnter the Accession number :");
                scanf("%d", &b1[i].accession_no);
                j = 0;
                k = i - 1;
            }
            else
            {
                j++;
                k--;
            }
        }
        printf("\n\tEnter Title of the Book : ");
        fflush(stdin);
        scanf("%[^\n]s", b1[i].title_of_book);
        printf("Enter Author Name :");
        fflush(stdin);
        scanf("%[^\n]s", b1[i].author_name);
        printf("Enter price of the Book :");
        fflush(stdin);
        scanf("%f", &b1[i].price);
    }
}
void display_added_books(book *b1, int m)
{
    for (i = 0; i < m; i++)
    {
        printf("\n\n\n\tAccession No. : %d", b1[i].accession_no);
        printf("\ttitle_of_book : %s", b1[i].title_of_book);
        printf("\n\t\t\t\tAuthor : %s", b1[i].author_name);
        printf("\t\tprice of book : %.2f", b1[i].price);
        printf("\n\n");
    }
}
void booksByauthor(book *b, book *b1, char *author, int m)
{
    int flag = 0;
    for (i = 0; i < AVAILABLEBOOKS; i++)
    {
        if ((strcmp(author, b[i].author_name)) == 0)
        {
            flag = 1;
            printf("\n\tAccession No. : %d", b[i].accession_no);
            printf("\ttitle_of_book : %s", b[i].title_of_book);
            printf("\tprice of book : %.2f", b[i].price);
            printf("\n\n");
        }
    }
    if (b1 != NULL)
    {
        for (i = 0; i < m; i++)
        {

            if ((strcmp(author, b1[i].author_name)) == 0)
            {
                flag = 1;
                printf("\n\tAccession No. : %d", b1[i].accession_no);
                printf("\ttitle_of_book : %s", b1[i].title_of_book);
                printf("\tprice of book : %.2f", b1[i].price);
                printf("\n\n");
            }
        }
    }
    if (flag == 0)
        printf("\n\n\t\t\tNo any book from %s present here", author);
}
void booksBytitle(book *b, book *b1, char *title, int m)
{
    int flag = 0;
    for (i = 0; i < AVAILABLEBOOKS; i++)
    {

        if ((strcmp(title, b[i].title_of_book)) == 0)
        {
            flag = 1;
            printf("\n\tAccession No. : %d", b[i].accession_no);
            printf("\ttitle_of_book : %s", b[i].title_of_book);
            printf("\tAuthor Name  : %s", b[i].author_name);
            printf("\tprice of book : %.2f", b[i].price);
            printf("\n\n");
        }
    }
    if (b1 != NULL)
    {
        for (i = 0; i < m; i++)
        {
            flag = 1;
            int w = strcmp(title, b1[i].title_of_book);
            if (w == 0)
            {
                printf("\n\tAccession No. : %d", b1[i].accession_no);
                printf("\ttitle_of_book : %s", b1[i].title_of_book);
                printf("\tAuthor Name  : %s", b1[i].author_name);
                printf("\tprice of book : %.2f", b1[i].price);
                printf("\n\n");
            }
        }
    }
    if (flag == 0)
        printf("\n\t\t\t\t\t\t\tUnable to search");
}
void sortByaceessonNumber(book *b, book *b1, int m)
{
    book temp;
    for (i = 0; i < AVAILABLEBOOKS; i++)
    {
        int j;
        for (j = 0; j < AVAILABLEBOOKS - i - 1; j++)
        {
            if (b[j].accession_no > b[j + 1].accession_no)
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}
void sortedbooks(book *b, book *b1, int m)
{
    if (b1 != NULL)
    {
        int total = AVAILABLEBOOKS + m;
        int j = 0;
        int a = findmin(b, b1, m, &flag);
        showBookInfo(b1, a);
        int d = findNext(b, b1, m, &flag);
        showBookInfo(b1, d);
        while (j++ < (total - 2))
        {
            smallest = next;
            int c = nextelement(b, b1, m, &flag);
            showBookInfo(b1, c);
        }
    }
    else
    {
        for (i = 0; i < AVAILABLEBOOKS; i++)
        {
            printf("\n\n\tAccession No. : %d", b[i].accession_no);
            printf("\ttitle_of_book : %s", b[i].title_of_book);
            printf("\n\tAuthor : %s", b[i].author_name);
            printf("\t\tprice of book : %.2f", b[i].price);
            printf("\n\n");
        }
    }
}

int findmin(book *b, book *b1, int m, int *flag)
{
    int min = b[0].accession_no;
    int q, j, a;
    for (j = 0; j < m; j++)
    {
        if (b1[j].accession_no < min)
        {
            min = b1[j].accession_no;
            smallest = min;
            a = j;
            *flag = 1;
            for (q = 0; q < AVAILABLEBOOKS; q++)
            {
                if (b[q].accession_no < min)
                {
                    *flag = 0;
                    min = b[q].accession_no;
                    smallest = min;
                    a = q;
                }
            }
        }
    }
    return a;
}
int findNext(book *b, book *b1, int m, int *flag)
{
    int j, q, a;
    int secMin = INT_MAX;
    for (j = 0; j < m; j++)
    {
        if ((b1[j].accession_no != smallest) && (b1[j].accession_no < secMin))
        {

            secMin = b1[j].accession_no;
            next = secMin;
            a = j;
            *flag = 1;
            for (q = 0; q < AVAILABLEBOOKS; q++)
            {
                if ((b[q].accession_no != smallest) && (b[q].accession_no < secMin))
                {
                    *flag = 0;
                    secMin = b[q].accession_no;
                    a = q;
                    next = secMin;
                }
            }
        }
    }
    return a;
}
int nextelement(book *b, book *b1, int m, int *f)
{
    int j, q, a;
    int secMin = INT_MAX;
    for (j = 0; j < m; j++)
    {
        if ((b1[j].accession_no != smallest) && (b1[j].accession_no < secMin) && (b1[j].accession_no > smallest))
        {

            secMin = b1[j].accession_no;
            next = secMin;
            a = j;
            *f = 1;
        }
    }
    for (q = 0; q < AVAILABLEBOOKS; q++)
    {
        if ((b[q].accession_no != smallest) && (b[q].accession_no < secMin) && (b[q].accession_no > smallest))
        {
            *f = 0;
            secMin = b[q].accession_no;
            a = q;
            next = secMin;
        }
    }
    return a;
}
void showBookInfo(book *b1, int x)
{
    if (flag == 1)
    {
        printf("\n\n\n\tAccession No. : %d", b1[x].accession_no);
        printf("\ttitle_of_book : %s", b1[x].title_of_book);
        printf("\n\t\t\t\tAuthor : %s", b1[x].author_name);
        printf("\t\tprice of book : %.2f", b1[x].price);
        printf("\n\n");
    }
    else
    {
        printf("\n\n\n\tAccession No. : %d", b[x].accession_no);
        printf("\ttitle_of_book : %s", b[x].title_of_book);
        printf("\n\t\t\t\tAuthor : %s", b[x].author_name);
        printf("\t\tprice of book : %.2f", b[x].price);
        printf("\n\n");
    }
}
