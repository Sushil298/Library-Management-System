#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <ctime>
#include <iterator>

using namespace std;
// forward declarations
class Accounts;
class Librarian;
void firstpage(Accounts, Librarian, string, string, string);

class Books
{
private:
    string name, author, publication;
    int bookid, quantity;
    double price;

public:
    // constructors
    Books() {}
    Books(string name, string author, string publication, int bookid, double price, int quantity)
    {
        this->name = name;
        this->author = author;
        this->publication = publication;
        this->bookid = bookid;
        this->price = price;
        this->quantity = quantity;
    }
    void setname(string name)
    {
        this->name = name;
    }
    void setauthor(string author)
    {
        this->author = author;
    }
    void setpublication(string publication)
    {
        this->publication = publication;
    }
    void setid(int id)
    {
        this->bookid = id;
    }
    void setprice(double price)
    {
        this->price = price;
    }
    void setquantity(int quantity)
    {
        this->quantity = quantity;
    }

    // getters
    string getname() const
    {
        return name;
    }
    string getauthor() const
    {
        return author;
    }
    string getpublication() const
    {
        return publication;
    }
    int getid() const
    {
        return bookid;
    }
    double getprice() const
    {
        return price;
    }
    int getquantity() const
    {
        return quantity;
    }

    void incrementquantity()
    {
        quantity--;
    }
    void decrementquantity()
    {
        quantity--;
    }
    inline void printinfo() const
    {
        cout << "Book ID: " << bookid << endl;
        cout << "Book name: " << name << endl;
        cout << "Publication: " << publication << endl;
        cout << "Author: " << author << endl;
        cout << "Available quantity: " << quantity << endl;
        cout << "Price: $ " << price << endl;
    }
    ~Books() {}
};

// transactions class
class transactions
{
private:
    int d1, m1, y1;
    int d2, m2, y2;
    string date1;
    string date2;
    string studentname;
    string studentid;
    int bookid;
    string bookname;
    string authorname;
    string publicationname;
    double bookprice;

public:
    // setters
    void setd1(int d)
    {
        this->d1 = d;
    }
    void setd2(int d)
    {
        this->d2 = d;
    }
    void setm1(int m)
    {
        this->m1 = m;
    }
    void setm2(int m)
    {
        this->m2 = m;
    }
    void sety1(int y)
    {
        this->y1 = y;
    }
    void sety2(int y)
    {
        this->y2 = y;
    }
    void setstudentname(string name)
    {
        studentname = name;
    }
    void setauthorname(string name)
    {
        authorname = name;
    }
    void setpublicationname(string name)
    {
        publicationname = name;
    }
    void setbookprice(double price)
    {
        bookprice = price;
    }

    void setstudentid(string id)
    {
        studentid = id;
    }
    void setbookid(int id)
    {
        bookid = id;
    }
    void setbookname(string name)
    {
        bookname = name;
    }
    void setissuedate(string date)
    {
        date1 = date;
    }
    void setreturndate(string date)
    {
        date2 = date;
    }
    // getters
    int getbookid() const
    {
        return bookid;
    }
    string getstudentid() const
    {
        return studentid;
    }
    string getstudentname() const
    {
        return studentname;
    }
    string getbookname() const
    {
        return bookname;
    }
    string getauthorname() const
    {
        return authorname;
    }
    string getpublicationname() const
    {
        return publicationname;
    }
    double getbookprice() const
    {
        return bookprice;
    }

    inline void setissuedate()
    { // finds the current time
        std::time_t t = std::time(0);
        // get date
        std::tm *now = std::localtime(&t);
        d1 = ((now->tm_year + 1900));
        m1 = (now->tm_mon + 1);
        y1 = (now->tm_mday);
    }
    inline void setreturndate()
    {
        // finds current time
        std::time_t t = std::time(0);
        // get date
        std::tm *now = std::localtime(&t);
        d2 = ((now->tm_year + 1900));
        m2 = (now->tm_mon + 1);
        y2 = (now->tm_mday);
    }

    string getissuedate() const
    {
        return date1;
    }
    string getreturndate() const
    {
        return date2;
    }
    // write the borrowed transactions to the file in append mode
    void writeissuetransaction(string filename_borrowedbooks)
    {
        ofstream outfile;
        outfile.open(filename_borrowedbooks, std::ios_base::app);
        if (outfile.fail())
        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        outfile << studentname << ','
                << studentid << ','
                << bookid << ','
                << bookname << ','
                << authorname << ','
                << publicationname << ','
                << bookprice << ','
                << y1 << "-" << m1 << "-" << d1 << ','
                << y2 << "-" << m2 << "-" << d2 << '\n';
        outfile.close();
    }

    // print the book issue confirmation message
    inline void printissuetransactions()
    {
        cout << "Student name: " << studentname
             << "\nStudent ID: " << studentid
             << "\nBorrowed Book ID: " << bookid
             << "\nBorrowed Book: " << bookname
             << "\nAuthor's name: " << authorname
             << "\nPublication: " << publicationname
             << "\nPrice: $ " << bookprice
             << "\nBorrowed date (DD-MM-YY): " << y1 << "-" << m1 << "-" << d1
             << "\nReturned date (DD-MM-YY): " << y2 << "-" << m2 << "-" << d2 << '\n';
    }
    // print the book return successful message
    inline void printreturntransactions()
    {
        setreturndate();
        cout << "Student name: " << studentname
             << "\nStudent ID: " << studentid
             << "\nBorrowed Book ID: " << bookid
             << "\nBorrowed Book: " << bookname
             << "\nAuthor's name: " << authorname
             << "\nPublication: " << publicationname
             << "\nPrice: $ " << bookprice
             << "\nBorrowed date (DD-MM-YY): " << date1
             << "\nReturned date (DD-MM-YY): " << y2 << "-" << m2 << "-" << d2 << endl;
    }

    // librarian class is made friend
    friend class Librarian;
};
// Accounts class
class Accounts
{
private:
public:
    // reads the books data from the file and stores in the list
    void readdata(string infilename, list<Books> &Bookobjects)
    {
        ifstream infile;
        string line;
        infile.open(infilename);
        if (infile.fail())
        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        // read the headings from file just to ignore
        getline(infile, line);
        Books obj;
        while (!infile.eof())
        {
            getline(infile, line);
            stringstream ss(line);
            string substr;

            if (line.empty())
            {
                break;
            }
            for (int i = 0; i < 6; i++)
            {
                getline(ss, substr, ',');
                switch (i)
                {

                case 0:
                    obj.setid(stoi(substr));
                    continue;
                case 1:
                    obj.setname(substr);
                    continue;
                case 2:
                    obj.setauthor(substr);
                    continue;
                case 3:
                    obj.setpublication(substr);
                    continue;
                case 4:
                    obj.setquantity(stoi(substr));
                    continue;

                case 5:
                    obj.setprice(stod(substr));
                    continue;

                default:
                    cout << "Count is beyond expected" << endl;
                }
            }
            Bookobjects.push_back(obj);
        }

        infile.close();
    }

    // searchin for the book in the system
    void search(string infilename, int selector, string searchtext)
    {
        list<Books> Bookobjects;
        readdata(infilename, Bookobjects);
        list<Books>::iterator itr;
        bool finder = false;

        for (itr = Bookobjects.begin(); itr != Bookobjects.end(); itr++)
        {
            if ((selector == 1 && stoi(searchtext) == itr->getid()) || (selector == 2 && searchtext == itr->getname()) || (selector == 3 && searchtext == itr->getauthor()))
            {
                cout << "******************************Availabe Books**************************" << endl;
                cout << "----------------------------------------------------------------------" << endl;
                itr->printinfo();
                cout << "----------------------------------------------------------------------" << endl;
                finder = true;
            }
        }
        if (!finder)
        {
            cout << "______________________________________________________________________" << endl;
            cout << "Sorry! Search result is not found." << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
    }
    // read the data of the borrowed books from the file
    void readdata(string infilename, list<transactions> &Bookobjects)
    {

        ifstream infile;
        string line;
        infile.open(infilename);
        if (infile.fail())

        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        // read the heading from file just to ignore
        getline(infile, line);

        // Objett to read the file into the system
        transactions obj;
        while (!infile.eof())
        {
            getline(infile, line);
            stringstream ss(line);
            string substr;

            if (line.empty())
            {
                break;
            }
            for (int i = 0; i < 9; i++)
            {
                getline(ss, substr, ',');
                switch (i)
                {

                case 0:
                    obj.setstudentname(substr);
                    continue;
                case 1:
                    obj.setstudentid(substr);
                    continue;
                case 2:
                    obj.setbookid(stoi(substr));
                    continue;
                case 3:
                    obj.setbookname(substr);
                    continue;
                case 4:
                    obj.setauthorname(substr);
                    continue;
                case 5:
                    obj.setpublicationname(substr);
                    continue;
                case 6:
                    obj.setbookprice(stod(substr));
                    continue;

                case 7:
                    obj.setissuedate(substr);
                    continue;

                case 8:
                    obj.setreturndate(substr);
                    continue;

                default:
                    cout << "Count is beyond expected" << endl;
                }
            }
            Bookobjects.push_back(obj);
        }
        infile.close();
    }
};

// librarian class
class Librarian : public Accounts
{
public:
    // Rewrites the list along with heading in the file
    void writebookdata(string outfilename, list<Books> &Bookobjects)
    {
        list<Books>::iterator itr;
        ofstream outfile;
        outfile.open(outfilename, std::ofstream::trunc);
        if (outfile.fail())
        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        // write headings
        outfile << "Book ID " << ','
                << "Book name " << ','
                << "Author's name " << ','
                << "Publication" << ','
                << "Quantity " << ','
                << "Price " << '\n';

        for (itr = Bookobjects.begin(); itr != Bookobjects.end(); itr++)
        {
            outfile << itr->getid() << ',';
            outfile << itr->getname() << ',';
            outfile << itr->getauthor() << ',';
            outfile << itr->getpublication() << ',';
            outfile << itr->getquantity() << ',';
            outfile << itr->getprice() << '\n';
        }
        outfile.close();
    }
    // Rewrites in the list along with headings of the borrowed books to the file
    void writedata(string outfilename, list<transactions> &Bookobjects)
    {
        list<transactions>::iterator itr;
        ofstream outfile;
        outfile.open(outfilename, std::ofstream::trunc);
        if (outfile.fail())
        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        // write headings
        outfile
            << "Student name " << ','
            << "Student ID " << ','
            << "Book ID " << ','
            << "Book name " << ','
            << "Author's name " << ','
            << "Publication " << ','
            << "Book price " << ','
            << "Issued date " << ','
            << "Return date " << '\n';

        for (itr = Bookobjects.begin(); itr != Bookobjects.end(); itr++)
        {
            outfile << itr->getstudentname() << ',';
            outfile << itr->getstudentid() << ',';
            outfile << itr->getbookid() << ',';
            outfile << itr->getbookname() << ',';
            outfile << itr->getauthorname() << ',';
            outfile << itr->getpublicationname() << ',';
            outfile << itr->getbookprice() << ',';
            outfile << itr->getissuedate() << ',';
            outfile << itr->getreturndate() << '\n';
        }
        outfile.close();
    }
    // Writes the record of the returned book along with borrowed and returned date to the file
    void writereturnedbooks(string outfilename, transactions bookdetail)
    {
        ofstream outfile;
        outfile.open(outfilename, std::ofstream::app);
        if (outfile.fail())
        {
            cerr << "Could not open the file" << endl;
            exit(-1);
        }
        string date2;
        bookdetail.setreturndate();
        date2 = to_string(bookdetail.y2) + "-" + to_string(bookdetail.m2) + "-" + to_string(bookdetail.d2);
        outfile << bookdetail.getstudentname() << ',';
        outfile << bookdetail.getstudentid() << ',';
        outfile << bookdetail.getbookid() << ',';
        outfile << bookdetail.getbookname() << ',';
        outfile << bookdetail.getauthorname() << ',';
        outfile << bookdetail.getpublicationname() << ',';
        outfile << bookdetail.getbookprice() << ',';
        outfile << bookdetail.getissuedate() << ',';
        outfile << date2 << '\n';
    }

    // adds the new book information to the file
    void addbook(string filename, int id, string name, string author, string publication, int quantity_num, double price)
    {
        ofstream outfile;
        list<Books> Bookobjects;
        readdata(filename, Bookobjects);
        list<Books>::iterator itr;
        bool found = false;
        system("clear");
        cout << "______________________________________________________________________" << endl;
        cout << "The following book is added to the library" << endl;
        // if book already exists, just increase the quantity
        for (itr = Bookobjects.begin(); itr != Bookobjects.end(); itr++)
        {
            if (id == itr->getid())
            {
                itr->setquantity(itr->getquantity() + quantity_num);
                writebookdata(filename, Bookobjects);
                found = true;

                itr->printinfo();
            }
        }

        // if book does not already exist, write the full information to the file
        if (!found)
        {
            outfile.open(filename, std::ofstream::app);
            if (outfile.fail())
            {
                cerr << "Could not open the file" << endl;
                exit(-1);
            }
            outfile << id << ',';
            outfile << name << ',';
            outfile << author << ',';
            outfile << publication << ',';
            outfile << quantity_num << ',';
            outfile << price << '\n';
            outfile.close();
            cout << "Book ID: " << id << endl;
            cout << "Book name: " << name << endl;
            cout << "Author: " << author << endl;
            cout << "Publication: " << publication << endl;
            cout << "Available quantity: " << quantity_num << endl;
            cout << "Price: $ " << price << endl;
        }
        cout << "----------------------------------------------------------------------" << endl;
    }
    // delete specific book from list of books in the file
    void deletedata(string infilename, int id)
    {

        list<Books> Bookobject1;
        list<Books> Bookobject2;
        readdata(infilename, Bookobject1);
        list<Books>::iterator itr;
        for (itr = Bookobject1.begin(); itr != Bookobject1.end(); itr++)
        {
            if (id == itr->getid())
            {
                if (itr->getquantity() == 1)
                {
                    system("clear");
                    cout << "______________________________________________________________________" << endl;
                    cout << "One copy of following book is taken from library." << endl;
                    cout << "----------------------------------------------------------------------" << endl;

                    itr->setquantity(itr->getquantity() - 1);
                    itr->printinfo();
                    cout << "______________________________________________________________________" << endl;
                    continue;
                }
                else if ((itr->getquantity() > 1))
                {
                    system("clear");
                    cout << "______________________________________________________________________" << endl;
                    cout << "One copy of following book is taken from library." << endl;
                    cout << "----------------------------------------------------------------------" << endl;
                    itr->decrementquantity();
                    itr->printinfo();
                    cout << "______________________________________________________________________" << endl;
                    Bookobject2.push_back(*itr);
                }
            }
            else
            {
                Bookobject2.push_back(*itr);
            }
        }

        writebookdata(infilename, Bookobject2);
    }
    // deleting the record of borrowed book. It occurs when the book is returned.
    void deletebook(string infilename, int bookid, string stid)
    {

        list<transactions> Bookobject1;
        list<transactions> Bookobject2;
        readdata(infilename, Bookobject1);
        list<transactions>::iterator itr;
        bool deleter = false;
        for (itr = Bookobject1.begin(); itr != Bookobject1.end(); itr++)
        {
            if (bookid == itr->getbookid() && stid == itr->getstudentid())
            {
                deleter = true;
                continue;
            }
            else
            {
                Bookobject2.push_back(*itr);
            }
        }

        writedata(infilename, Bookobject2);

        if (deleter)
        {
            cout << "The book has been deleted from borrowed list." << endl;
        }
        else
        {
            cout << "The book does not exist to delete" << endl;
        }
    }
    // Issue book to the student
    void Issuebook(string filename_booklist, string filename_borrowedbooks, string stid, string stname, int bookid)
    {
        bool available = false;
        transactions issue;
        issue.studentname = stname;
        issue.studentid = stid;
        list<Books> Bookobjects;
        readdata(filename_booklist, Bookobjects);
        list<Books>::iterator itr;
        for (itr = Bookobjects.begin(); itr != Bookobjects.end(); itr++)
        {
            if (itr->getid() == bookid)
            {
                available = true;
                deletedata(filename_booklist, bookid);
                issue.setissuedate();
                issue.bookname = itr->getname();
                issue.bookid = itr->getid();
                issue.d2 = 0;
                issue.m2 = 0;
                issue.y2 = 0;
                issue.authorname = itr->getauthor();
                issue.publicationname = itr->getpublication();
                issue.bookprice = itr->getprice();
                issue.writeissuetransaction(filename_borrowedbooks);
                system("clear");
                cout << "______________________________________________________________________" << endl;
                cout << "The book is issued to the following student." << endl;
                cout << "----------------------------------------------------------------------" << endl;
                issue.printissuetransactions();
                cout << "----------------------------------------------------------------------" << endl;
            }
        }
        if (!available)
        {
            cout << "Book is not available." << endl;
        }
    }
    // Keep the informatin of returned book
    void returnbook(string filename_booklist, string filename_borrowedbooks, string returnfile, int bookid, string stid)
    {
        list<transactions> borrowobjects;
        readdata(filename_borrowedbooks, borrowobjects);
        list<transactions>::iterator itr;
        bool found = false;
        for (itr = borrowobjects.begin(); itr != borrowobjects.end(); itr++)
        {

            if (itr->getstudentid() == stid && itr->getbookid() == bookid)
            {
                deletebook(filename_borrowedbooks, bookid, stid);
                writereturnedbooks(returnfile, *itr);
                addbook(filename_booklist, itr->getbookid(), itr->getbookname(), itr->getauthorname(), itr->getpublicationname(), 1, itr->getbookprice());
                system("clear");
                cout << "______________________________________________________________________" << endl;
                cout << "The book is returned from the following student." << endl;
                cout << "----------------------------------------------------------------------" << endl;
                itr->printreturntransactions();
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Thank you for returning the book." << endl;
                found = true;
            }
        }
        if (!found)
        {

            cout << "______________________________________________________________________" << endl;
            cout << "No record of such borrowed book exist in the system." << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
    }
};

// Functions which are not inside the classes
// these are for the menu display and are called inside main
void librarianworks(Librarian L, Accounts A, string Recordfile, string Loansfile, string Returnedbooksfile)
{
    int choice, selector;
    string searchtext;
    int bookid, quantity;
    string bookname, author, publication;
    string studentname, studentid;
    double price;
    system("clear");
    cout << "Select your choice: " << endl;
    cout << "1. Search book\n2. Add book\n3. Delete book\n4. Issue Book \n5. Return Book\n6. Go back to main menu \n7. Terminate program" << endl;
    cin >> choice;
    system("clear");
    int num;
    bool r = true;
    bool repeat = true;
    while (repeat)
    {
        switch (choice)
        {
        case 1:
            while (r)
            {
                cout << "Select your search method:\n1. By book id (integer, recommended)\n2. By book name\n3. By author's name\n4. Go back\n5. Terminate" << endl;
                cin >> selector;
                system("clear");
                if (selector == 1)
                {
                    cout << "Enter the book ID (integer):" << endl;
                    cin >> searchtext;
                    system("clear");
                    L.search(Recordfile, selector, searchtext);
                }
                else if (selector == 2)
                {
                    cout << "Enter the book name:" << endl;
                    getline(cin.ignore(), searchtext);
                    system("clear");
                    L.search(Recordfile, selector, searchtext);
                }
                else if (selector == 3)
                {
                    cout << "Enter the author's full name:" << endl;
                    getline(cin.ignore(), searchtext);
                    system("clear");
                    L.search(Recordfile, selector, searchtext);
                }
                else if (selector == 4)
                {
                    librarianworks(L, A, Recordfile, Loansfile, Returnedbooksfile);
                    repeat = false;

                    break;
                }
                else if (selector == 5)
                {
                    cout << "Program terminating..." << endl;
                    exit(-1);
                }
                else
                {
                    cout << "Invalid choice. Please enter correctly." << endl;
                    continue;
                }
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Enter 1 to continue searching and any other key to terminate." << endl;
                cin >> num;
                if (num != 1)
                {
                    r = false;
                }
                system("clear");
            }
            repeat = false;
            break;
        case 2:

            while (r)
            {
                system("clear");
                cout << "Enter the book id (integer):" << endl;
                cin >> bookid;
                cout << "Enter the book name:" << endl;
                getline(cin.ignore(), bookname);
                cout << "Enter the author's name:" << endl;
                getline(cin, author);
                cout << "Enter the publication name:" << endl;
                getline(cin, publication);
                cout << "Enter the number of books:" << endl;
                cin >> quantity;
                cout << "Enter the price of a book ($):" << endl;
                cin >> price;
                L.addbook(Recordfile, bookid, bookname, author, publication, quantity, price);
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Enter 1 to add another book and any other key to terminate." << endl;
                cin >> num;
                if (num != 1)
                {
                    r = false;
                }
                system("clear");
            }
            repeat = false;
            break;
        case 3:
            while (r)
            {
                cout << "Enter the book id (integer): " << endl;
                cin >> bookid;
                L.deletedata(Recordfile, bookid);
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Enter 1 to delete another book and any other key to terminate." << endl;
                cin >> num;
                if (num != 1)
                {
                    r = false;
                }
                system("clear");
            }
            repeat = false;
            break;
        case 4:
            while (r)
            {
                cout << "Enter the ID (integer) of book you want to issue." << endl;
                cin >> bookid;
                cout << "Enter the name of the borrower/student." << endl;
                getline(cin.ignore(), studentname);
                cout << "Enter the ID (aphanumeric) of the student." << endl;
                getline(cin, studentid);
                L.Issuebook(Recordfile, Loansfile, studentid, studentname, bookid);
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Enter 1 to issue another book and any other key to terminate." << endl;
                cin >> num;
                if (num != 1)
                {
                    r = false;
                }
                system("clear");
            }
            repeat = false;
            break;
        case 5:
            while (r)
            {
                cout << "Enter the ID (integer) of book which is to be returned." << endl;
                cin >> bookid;
                cout << "Enter the ID (aphanumeric) of the student who had borrowed the book." << endl;
                getline(cin.ignore(), studentid);

                L.returnbook(Recordfile, Loansfile, Returnedbooksfile, bookid, studentid);
                cout << "----------------------------------------------------------------------" << endl;
                cout << "Enter 1 to return another book and any other key to terminate." << endl;
                cin >> num;
                if (num != 1)
                {
                    r = false;
                }
                system("clear");
            }
            repeat = false;
            break;
        case 6:
            firstpage(A, L, Recordfile, Loansfile, Returnedbooksfile);
            repeat = false;
            break;
        case 7:
            cout << "Program terminating..." << endl;
            repeat = false;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
// function for other people than librarian. Maybe student or any reader
void otheraccounts(Accounts A, Librarian L, string Recordfile, string Loansfile, string Returnedbooksfile)
{
    system("clear");
    string searchtext;
    int selector;
    bool r = true;
    int num;

    cout << "You can search for the books in the library" << endl;
    while (r)
    {
        cout << "Select your search method:\n1. By book id (integer, recommended)\n2. By book name\n3. By author's name\n4. Go back to main menu\n5. Terminate" << endl;
        cin >> selector;
        system("clear");
        if (selector == 1)
        {
            cout << "Enter the book ID (integer):" << endl;
            cin >> searchtext;
            system("clear");
            A.search(Recordfile, selector, searchtext);
        }
        else if (selector == 2)
        {
            cout << "Enter the book name:" << endl;
            getline(cin.ignore(), searchtext);
            system("clear");
            A.search(Recordfile, selector, searchtext);
        }
        else if (selector == 3)
        {
            cout << "Enter the author's full name:" << endl;
            getline(cin.ignore(), searchtext);
            system("clear");
            A.search(Recordfile, selector, searchtext);
        }
        else if (selector == 4)
        {
            firstpage(A,  L, Recordfile,  Loansfile,  Returnedbooksfile);
            //break;
        }
        else if (selector == 5)
        {
            cout << "Program terminating..." << endl;
            exit(-1);
        }
        else
        {
            cout << "Invalid choice. Please enter correctly." << endl;
            continue;
        }
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Enter 1 to continue searching and any other key to terminate." << endl;
        cin >> num;
        if (num != 1)
        {
            r = false;
        }
        system("clear");
    }
    
}


void firstpage(Accounts A, Librarian L, string Recordfile, string Loansfile, string Returnedbooksfile)
{
    int choice;
    cout << "Log in as: " << endl;
    cout << "1. Librarian\n2. Student\n3. Terminate" << endl;
    cin >> choice;
    bool repeat = true;
    while (repeat)
    {
        switch (choice)
        {
        case 1:
            librarianworks(L, A, Recordfile, Loansfile, Returnedbooksfile);
            repeat = false;
            break;
        case 2:

            otheraccounts(A, L, Recordfile, Loansfile, Returnedbooksfile);
            repeat = false;
            break;
        case 3:
            cout << "Program terminating..." << endl;
            repeat = false;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}
int main()
{
    string Recordfile = "Data.csv", Loansfile = "loans.csv", Returnedbooksfile = "Returnedbooks.csv";
    Accounts A;
    Librarian L;
    firstpage(A, L, Recordfile, Loansfile, Returnedbooksfile);
}