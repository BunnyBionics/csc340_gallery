//created by: BunnyBionics
//date: Nov 19th 2025

#include "Customer_Curation_Sale_Gallery.h"

namespace NS_ARTGALLERY{
    using namespace std;

    // Customer member functions
    Customer::Customer()
    {
        ID = -1;
        name = "na";
        email = "na";
        address = "na";
    }

    Customer::Customer(int theID, string theName, string theEmail, const string theAddr)
    {
        ID = theID;
        name = theName;
        email = theEmail;
        address = theAddr;
    }

    int Customer::getID() const
    {
        return ID;
    }

    string Customer::getName() const
    {
        return name;
    }

    string Customer::getEmail() const
    {
        return email;
    }

    string Customer::getAddress() const
    {
        return address;
    }

    void Customer::setID(int theID)
    {
        ID = theID;
    }

    void Customer::setName(string theName)
    {
        name = theName;
    }

    void Customer::setEmail(string theEmail)
    {
        email = theEmail;
    }

    void Customer::setAddress(string theAddress)
    {
        address = theAddress;
    }

    // Curation member functions
    Curation::Curation()
    {
        artworkID = -1;
        artistID = -1;
        curationDate = Date {1, 1, 2022};
    }

    Curation::Curation(int theArtworkID, int theArtistID, Date theDate)
    {
        artworkID = theArtworkID;
        artistID = theArtistID;
        curationDate = theDate;
    }





}//end of NS_ARTGALLERY