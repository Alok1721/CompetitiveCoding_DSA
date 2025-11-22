#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    static int id;
    int bookId;
    string title;
    string author;
    string publisher;
    int totalCopies;
    int availableCopies;

    Book(string title, string author, string publisher, int totalCopies) {
        this->bookId = ++Book::id; // ✅ fixed
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->totalCopies = totalCopies;
        this->availableCopies = totalCopies;
    }

    void displayInfo() {
        cout << "----------------------------" << endl;
        cout << "Book ID: " << bookId
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nPublisher: " << publisher
             << "\nTotal Copies: " << totalCopies
             << "\nAvailable Copies: " << availableCopies << endl;
    }
};
int Book::id = 0;
// ...existing code...
class Member {
public:
    static int id;
    int memberId;
    int maxBooks;
    string name;
    unordered_set<int> issuedBooks;

    Member(int maxBooks, string name) {
        this->memberId = ++Member::id; // ✅ fixed
        this->maxBooks = maxBooks;
        this->name = name;
    }

    bool canIssue(int bookId) {
        if (issuedBooks.count(bookId)) {
            cout << "Already issued" << endl;
            return false;
        }
        if (issuedBooks.size() >= maxBooks) {
            cout << "Max limit hit for book issue" << endl;
            return false;
        }
        return true;
    }

    bool issueBook(int bookId) {
        if (issuedBooks.count(bookId)) {
            cout << "Already issued" << endl;
            return false;
        }
        issuedBooks.insert(bookId);
        return true;
    }

    bool returnBook(int bookId) {
        if (!issuedBooks.count(bookId)) {
            cout << "Book not present" << endl;
            return false;
        }
        issuedBooks.erase(bookId);
        cout << "Book returned successfully" << endl;
        return true;
    }
};
// ...existing code...
class Library {
public:
    unordered_map<int, Book> books;
    unordered_map<int, Member*> members;
    unordered_map<int, unordered_map<int, Transaction>> transactions;
    int transactionCounter;

    Library() {
        transactionCounter = 0;
    }

    void addBook(const Book &book) {
        if (books.count(book.bookId)) {
            cout << "Already added book" << endl;
            return;
        }
        books[book.bookId] = book;
    }

    void addMember(Member* member) {
        if (members.count(member->memberId)) {
            cout << "Member already present" << endl;
            return;
        }
        members[member->memberId] = member;
    }

    bool canIssue(int memberId, int bookId) {
        if (!members.count(memberId)) {
            cout << "Member not present,Register first" << endl;
            return false;
        }
        if (!books.count(bookId)) {
            cout << "Book not present,add the BOOK in Library system" << endl;
            return false;
        }

        Member* member = members[memberId];
        Book& book = books[bookId];

        if (book.availableCopies <= 0) {
            cout << "Book copy not available" << endl;
            return false;
        }

        return member->canIssue(bookId);
    }

    void addNewTransaction(Transaction transaction) {
        transactions[transaction.memberId][transaction.bookId] = transaction;
    }

    void updateTransaction(int memberId, int bookId, string returnDate, bool isReturned) {
        Transaction& transaction = transactions[memberId][bookId];
        transaction.isReturned = isReturned;
        transaction.returnDate = returnDate;
        cout << "Transaction updated with id " << transaction.transactionId << endl;
    }

    void createTransaction(int memberId, int bookId, string dueDate) {
        Transaction transaction;
        transaction.transactionId = ++transactionCounter;
        transaction.memberId = memberId;
        transaction.bookId = bookId;
        transaction.isReturned = false;
        transaction.dueDate = dueDate;
        transaction.returnDate = "";
        addNewTransaction(transaction);
        cout << "Transaction created with id " << transaction.transactionId << endl;
    }

    void issueBook(int memberId, int bookId, string dueDate) {
        if (!canIssue(memberId, bookId)) {
            return;
        }

        Member* member = members[memberId];
        Book& book = books[bookId];

        if (!member->issueBook(bookId)) {
            return;
        }

        book.availableCopies--;
        createTransaction(memberId, bookId, dueDate);
    }

    void returnBook(int memberId, int bookId) {
        if (!members.count(memberId)) {
            cout << "Member not present" << endl;
            return;
        }
        if (!books.count(bookId)) {
            cout << "Book not present" << endl;
            return;
        }

        Member* member = members[memberId];
        Book& book = books[bookId];

        if (!member->returnBook(bookId)) {
            return;
        }

        book.availableCopies++;

        time_t now = time(0);
        string returnDate = ctime(&now);
        returnDate.pop_back();
        updateTransaction(memberId, bookId, returnDate, true);
    }
};
// ...existing code...

int main() {
    Library library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 5));
    library.addMember(new Member(3, "Alice"));
    library.issueBook(1, 1, "2024-12-31");
    library.returnBook(1, 1);
    return 0;
}
