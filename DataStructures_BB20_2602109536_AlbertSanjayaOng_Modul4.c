#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 50
#define MIN_TITLE_LENGTH 5
#define MAX_AUTHOR_LENGTH 25
#define MIN_AUTHOR_LENGTH 3
#define MAX_ISBN_LENGTH 13
#define MIN_ISBN_LENGTH 10
#define MIN_PAGE_NUMBER 16
#define TABLE_SIZE 1007


typedef struct Book
{
  char id[20];
  char title[MAX_TITLE_LENGTH + 1];
  char author[MAX_AUTHOR_LENGTH + 1];
  char isbn[MAX_ISBN_LENGTH + 1];
  int num_pages;
  struct Book *next;
} Book;


typedef struct HashTable
{
  Book *table[TABLE_SIZE];
} HashTable;


int menu ();
void view_books (HashTable * ht);
void insert_book (HashTable * ht);
void remove_book (HashTable * ht);
void print_book (Book * book);
int validate_title (char *title);
int validate_author (char *author);
int validate_isbn (char *isbn);
int validate_num_pages (int num_pages);
int hash_function (char *key);

int main ()
{

  HashTable ht;
  memset (&ht, 0, sizeof (HashTable));

  while (1)
    {
	    printf ("Bluejack Library\n");
		printf ("=================\n");
		printf ("1. View Book\n");
		printf ("2. Insert Book\n");
		printf ("3. Remove Book\n");
		printf ("4. Exit\n");
		printf (">> ");
		int choice;
		scanf ("%d", &choice);
	    switch (choice)
		{
		case 1:
		  view_books (&ht);
		  break;
		case 2:
		  insert_book (&ht);
		  break;
		case 3:
		  remove_book (&ht);
		  break;
		case 4:
		  return 0;
		default:
		  printf ("Invalid choice, please try again.\n");
		}
    }
}


int menu ()
{
  printf ("\nBluejack Library ---\n");
  printf ("1. View Book\n");
  printf ("2. Insert Book\n");
  printf ("3. Remove Book\n");
  printf ("4. Exit\n");
  printf (">> ");
  int choice;
  scanf ("%d", &choice);
}


void
view_books (HashTable * ht)
{
  int i;
  int found = 0;
  for(int i=0; i<100; i++){
  	printf ("-");
  }
  printf (" %-24s | %-49s | %-24s | %-13s | %-12s |\n","Book ID","Book Title","Book Author","ISBN","Page Number");
  for (i = 0; i < TABLE_SIZE; i++)
    {
	      Book *book = ht->table[i];
	      while (book != NULL)
		{
		  print_book (book);
		  book = book->next;
		  found = 1;
		}
    }
  if (!found)
    {
      printf ("There is no book(s) !\n");
    }
}


void
insert_book (HashTable * ht)
{
  printf ("\n--- Insert Book ---\n");
  Book *book = (Book *) malloc (sizeof (Book));


  while (1)
    {
      printf ("Book Title (between %d and %d characters): ", MIN_TITLE_LENGTH,
	      MAX_TITLE_LENGTH);
      char title[MAX_TITLE_LENGTH + 1];
      scanf ("%s", title);
      if (validate_title (title))
	{
	  if (strlen (title) > MAX_TITLE_LENGTH)
	    {
	      printf ("Title is too long, please try again.\n");
	    }
	  else
	    {
	      strcpy (book->title, title);
	      break;
	    }
	}
      else
	{
	  printf ("Title is not valid, please try again.\n");
	}
    }

  while (1)
    {
      printf ("Author Name (between %d and %d characters): ",
	      MIN_AUTHOR_LENGTH, MAX_AUTHOR_LENGTH);
      char author[MAX_AUTHOR_LENGTH + 1];
      scanf ("%s", author);
      if (validate_author (author))
	{
	  if (strlen (author) > MAX_AUTHOR_LENGTH)
	    {
	      printf ("Author name is too long, please try again.\n");
	    }
	  else
	    {
	      strcpy (book->author, author);
	      break;
	    }
	}
      else
	{
	  printf ("Author name is not valid, please try again.\n");
	}
    }


  while (1)
    {
      printf ("ISBN (between %d and %d digits): ", MIN_ISBN_LENGTH,
	      MAX_ISBN_LENGTH);
      char isbn[MAX_ISBN_LENGTH + 1];
      scanf ("%s", isbn);
      if (validate_isbn (isbn))
	{
	  if (strlen (isbn) > MAX_ISBN_LENGTH)
	    {
	      printf ("ISBN is too long, please try again.\n");
	    }
	  else
	    {
	      strcpy (book->isbn, isbn);
	      break;
	    }
	}
      else
	{
	  printf ("ISBN is not valid, please try again.\n");
	}
    }


  while (1)
    {
      printf ("Number of Pages (minimum %d pages): ", MIN_PAGE_NUMBER);
      int num_pages;
      scanf ("%d", &num_pages);
      if (validate_num_pages (num_pages))
	{
	  book->num_pages = num_pages;
	  break;
	}
      else
	{
	  printf ("Number of pages is not valid, please try again.\n");
	}
    }

  int index = hash_function (book->isbn);
  book->next = ht->table[index];
  ht->table[index] = book;
  printf ("Book has been added to the library!\n");
}


void
remove_book (HashTable * ht)
{
  printf ("\n--- Remove Book ---\n");
  printf ("Enter the ISBN of the book you want to remove: ");
  char isbn[MAX_ISBN_LENGTH + 1];
  scanf ("%s", isbn);
  int index = hash_function (isbn);
  Book *book = ht->table[index];
  Book *prev_book = NULL;
  while (book != NULL)
    {
      if (strcmp (book->isbn, isbn) == 0)
	{
	  if (prev_book == NULL)
	    {
	      ht->table[index] = book->next;
	    }
	  else
	    {
	      prev_book->next = book->next;
	    }
	  free (book);
	  printf ("Book has been removed from the library!\n");
	  return;
	}
      prev_book = book;
      book = book->next;
    }
  printf ("Book with the ISBN %s was not found in the library.\n", isbn);
}

void print_book(Book *book)
{
    printf (" %-24s | %-49s | %-24s | %-13s | %-12d |\n",book->id,book->title,book->author,book->isbn,book->num_pages);
    for(int i=0; i<100; i++){
  		printf ("-");
  	}
}
