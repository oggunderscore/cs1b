#ifndef BOOKDATA_HPP_
#define BOOKDATA_HPP_

#include <string>

using namespace std;

class bookType
{
    public:
        void setTitle (string title);
        void setISBN (string isbn);
        void setAuthor (string author);
        void setPublisher (string publisher);
        void setDateAdded (string date);
        void setQty (int qty);
        void setWholesale (double wholesale);
        void setRetail (double retail);
        void setAll(string initTitle, 
                    string initISBN, 
                    string initAuthor, 
                    string initPublisher, 
                    string initDate, 
                    int initQty, 
                    double initWholesale, 
                    double initRetail
                    );

        //make these consts
        string getBookTitle();
        string getISBN();
        string getAuthor();
        string getPublisher();
        string getDateAdded();
        int getQtyAdded();
        double getWholesale();
        double getRetail();

        void print();
		static void incBookCount();
        static void decBookCount();
        static int getBookCount();  
    
     private:
        string bookTitle;
        string isbn;
        string author;
        string publisher;
        string dateAdded;
        int qtyOnHand;
        double wholesale;
        double retail;
        static int bookCount;

    
    
    
};
#endif