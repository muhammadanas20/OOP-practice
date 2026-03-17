// Question 2: Dynamic Memory Allocation, Copy Constructors, and Destructors
// Topics Covered: Pointers & DMA (02), Array of Objects (05), Constructors & Destructors (04).
// Scenario: You are working for a library, and they want an automated system to manage their books
// .
// Requirements:
// Class Definition: Create a class called Book with the following private attributes: Name (String), ISBN (String), Author (Char pointer, assume 30 characters), Genre (String), and Count (to keep track of the number of Book objects created)
// .
// Constraints: The ISBN is issued at the time of object creation and cannot be changed afterwards
// .
// Constructors: Make use of parameterized and copy constructors as necessary
// . Constructors should increase the static [Count] by 1
// .
// Destructor & DMA: Your class must have a destructor that deallocates memory dynamically allocated for [Author] using pointers, and it should also decrease the [Count] by 1
// .
// Implementation: Allow the user to input the number of books they want to add, then dynamically create an array to store those books
// . Provide a menu-driven program to allow users to edit all attributes (except ISBN and Count) and display the current number of books in the library
// . Finally, demonstrate the working of your copy constructor by copying one Book object to another
// .
#include <iostream>
#include <cstring>
using namespace std;
class Book{
    private:
    string name;
    string ISBN;
    char* Author;
    string genre;
    static int count;
    public:
    Book(string name, string ISBN, const char* author, string genre) {
        this->name = name;
        this->ISBN = ISBN;
        this->genre = genre;
        this->Author = new char[30];
        strncpy(this->Author, author, 29);
        this->Author[29] = '\0';
        count++;
    }
    // Copy Constructor
    Book(const Book& other) {
        name = other.name;
        ISBN = other.ISBN;
        genre = other.genre;
        Author = new char[30];
        strncpy(Author, other.Author, 30);
        count++;
    }

    // Destructor
    ~Book() {
        delete[] Author;
        count--;
    }

    // Edit attributes except ISBN and Count
    void edit() {
        cout << "Edit Name: ";
        getline(cin >> ws, name);
        cout << "Edit Author: ";
        char temp[30];
        cin.getline(temp, 30);
        strncpy(Author, temp, 30);
        cout << "Edit Genre: ";
        getline(cin, genre);
    }

    // Display Book details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Author: " << Author << endl;
        cout << "Genre: " << genre << endl;
    }

    // Static function to get count
    static int getCount() {
        return count;
    }
};

int Book::count = 0;

int main() {
    int n;
    cout << "Enter number of books to add: ";
    cin >> n;
    cin.ignore();

    // Dynamically allocate array of Book objects
    Book** library = new Book*[n];

    for (int i = 0; i < n; i++) {
        string name, isbn, genre;
        char author[30];
        cout << "\n--- Book " << i + 1 << " ---\n";
        cout << "Name: "; getline(cin, name);
        cout << "ISBN: "; getline(cin, isbn);
        cout << "Author: "; cin.getline(author, 30);
        cout << "Genre: "; getline(cin, genre);
        library[i] = new Book(name, isbn, author, genre);
    }

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Edit a book\n";
        cout << "2. Display all books\n";
        cout << "3. Show total book count\n";
        cout << "4. Demonstrate copy constructor\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int idx;
            cout << "Enter book index (1-" << n << "): ";
            cin >> idx; cin.ignore();
            if (idx >= 1 && idx <= n)
                library[idx - 1]->edit();
            else
                cout << "Invalid index.\n";
        } else if (choice == 2) {
            for (int i = 0; i < n; i++) {
                cout << "\n--- Book " << i + 1 << " ---\n";
                library[i]->display();
            }
        } else if (choice == 3) {
            cout << "Total books in library: " << Book::getCount() << endl;
        } else if (choice == 4) {
            int idx;
            cout << "Enter book index to copy (1-" << n << "): ";
            cin >> idx; cin.ignore();
            if (idx >= 1 && idx <= n) {
                Book copy(*library[idx - 1]);  // copy constructor
                cout << "\nCopied Book Details:\n";
                copy.display();
                cout << "Count after copy (includes temp): " << Book::getCount() << endl;
            } else {
                cout << "Invalid index.\n";
            }
        }
    } while (choice != 0);

    // Cleanup
    for (int i = 0; i < n; i++)
        delete library[i];
    delete[] library;

    cout << "Count after cleanup: " << Book::getCount() << endl;
    return 0;
}
