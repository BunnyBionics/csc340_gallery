//created by: BunnyBionics
//date: Nov 19th 2025

#include "Customer_Curation_Sale_Gallery.h"
#include <algorithm>
#include <ranges>
#include <set>
#include <vector>


namespace NS_ARTGALLERY
{
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
        curationDate = Date{1, 1, 2022};
    }

    Curation::Curation(int theArtworkID, int theArtistID, Date theDate)
    {
        artworkID = theArtworkID;
        artistID = theArtistID;
        curationDate = theDate;
    }

    int Curation::getArtworkID() const
    {
        return artworkID;
    }

    int Curation::getArtistID() const
    {
        return artistID;
    }

    Date Curation::getCurationDate() const
    {
        return curationDate;
    }

    void Curation::setArtworkID(int theID)
    {
        artworkID = theID;
    }

    void Curation::setArtistID(int theID)
    {
        artistID = theID;
    }

    void Curation::setCurationDate(Date theDate)
    {
        curationDate = theDate;
    }

    // Sale member function
    Sale::Sale()
    {
        customerID = -1;
        artworkID = -1;
        saleDate = Date{1, 1, 2022};
    }

    Sale::Sale(int theCustomerID, int theArtworkID, Date theDate)
    {
        customerID = theCustomerID;
        artworkID = theArtworkID;
        saleDate = theDate;
    }

    int Sale::getCustomerID() const
    {
        return customerID;
    }

    int Sale::getArtworkID() const
    {
        return artworkID;
    }

    Date Sale::getSaleDate() const
    {
        return saleDate;
    }

    void Sale::setCustomerID(int theID)
    {
        customerID = theID;
    }

    void Sale::setArtworkID(int theID)
    {
        artworkID = theID;
    }

    void Sale::setSaleDate(Date theDate)
    {
        saleDate = theDate;
    }

    // Gallery member functions
    Gallery::Gallery()
    {
        ID = -1;
        name = "na";
        address = "na";
        webURL = "na";
    }

    // accesors
    int Gallery::getID() const
    {
        return ID;
    }

    string Gallery::getName() const
    {
        return name;
    }

    string Gallery::getAddress() const
    {
        return address;
    }

    string Gallery::getWebURL() const
    {
        return webURL;
    }

    unsigned long Gallery::num_artists() const
    {
        return artistsList.size();
    }

    unsigned long Gallery::num_artworksCurated() const
    {
        return artworksCurated.size();
    }

    unsigned long Gallery::num_artworksForSale() const
    {
        return artworksForSale.size();
    }

    unsigned long Gallery::num_customers() const
    {
        return customersList.size();
    }

    unsigned long Gallery::num_curations() const
    {
        return curationsRecords.size();
    }

    unsigned long Gallery::num_sales() const
    {
        return salesRecords.size();
    }

    int Gallery::getArtistID(string name, string email) const
    {
        for (Artist person : artistsList)
        {

            if (person.getName() == name && person.getEmail() == email)
            {
                return person.getID();
            }
        }

        return -1;
    }

    int Gallery::getCustomerID(string name, string email) const
    {
        for (const Customer& person : customersList)
        {
            if (person.getName() == name && person.getEmail() == email)
            {
                return person.getID();
            }
        }

        return -1;
    }

    vector<int> Gallery::getIDsOfArtworksForSale() const
    {
        vector<int> artwork_ids;
        artwork_ids.reserve(artworksForSale.size());
        for (Artwork work : artworksForSale)
        {
            artwork_ids.push_back(work.getID());
        }

        return artwork_ids;
    }

    vector<int> Gallery::getIDsOfArtistsForSale() const
    {
        set<int> unique_ids;
        for (Artwork work : artworksForSale)
        {
            unique_ids.insert(work.getArtistID());
        }

        vector<int> artist_ids;
        artist_ids.reserve(unique_ids.size());
        for (int id : unique_ids)
        {
            artist_ids.push_back(id);
        }

        return artist_ids;
    }

    vector<pair<string, int>> Gallery::genArtworksReport(ReportType reportType)
    {
        using enum ReportType; // C++ 20, may need to change
        vector<pair<string, int>> report;
        const vector<Artwork> ac = artworksCurated;
        if (reportType == artType)
        {
            using enum ArtType;
            for (ArtType medium : vector{painting, photography, drawing, sculpture, other})
            {
                auto count = count_if(ac.begin(), ac.end(), [medium](const Artwork& art)
                {
                    return art.getType() == medium;
                });

                pair<string, int> row = {toStr_ArtType(medium), count};
                report.push_back(row);
            }
        } else if (reportType == artStyle)
        {
            using enum ArtStyle;
            for (ArtStyle art_style: vector{fineArt, abstract, modern, popArt, other})
            {
                auto count = count_if(ac.begin(), ac.end(), [art_style](Artwork art)
                {
                    return art.getStyle() == art_style;
                });

                pair<string, int> row = {toStr_ArtStyle(art_style), count};
                report.push_back(row);
            }
        } else if (reportType == artSubject)
        {
            using enum ArtSubject;
            for (ArtSubject art_subject: vector{nature, portrait, animal, cartoon, other})
            {
                auto count = count_if(ac.begin(), ac.end(), [art_subject](Artwork art)
                {
                    return art.getSubject() == art_subject;
                });

                pair<string, int> row = {toStr_ArtSubject(art_subject), count};
                report.push_back(row);
            }
        }

            return report;
    }

    // mutators
    void Gallery::setID(int theID)
    {
        ID = theID;
    }

    void Gallery::setName(string theName)
    {
        name = theName;
    }

    void Gallery::setAddress(string theAddr)
    {
        address = theAddr;
    }

    void Gallery::setWebURL(string theURL)
    {
        webURL = theURL;
    }

    int Gallery::addArtist(Artist artist)
    {
        if (getArtistID(artist.getName(), artist.getEmail()) != -1)
        {
            return -1; // already on list
        }
        artist.setID(uniqueIDs::next_artistID());
        artistsList.push_back(artist);
        return artist.getID();
    }

    int Gallery::addCustomer(Customer customer)
    {
        if (getCustomerID(customer.getName(), customer.getEmail()) != -1)
        {
            return -1; // alrady on list
        }
        customer.setID(uniqueIDs::next_customerID());
        customersList.push_back(customer);
        return customer.getID();
    }

    void Gallery::curateArtwork(Artwork newItem, Artist artist)
    {
        Curation newCuration;
        newItem.setID(uniqueIDs::next_artworkID());
        newCuration.setArtworkID(newItem.getID());
        int artist_id = getArtistID(artist.getName(), artist.getEmail());
        if (artist_id == -1)
        {
            artist_id = addArtist(artist);
        }

        newCuration.setArtistID(artist_id);
        newItem.setArtistID(artist_id);
        newCuration.setCurationDate(getTodaysDate());
        artworksCurated.push_back(newItem);
        artworksForSale.push_back(newItem);
        curationsRecords.push_back(newCuration);
    }

    void Gallery::sellArtwork(int artworkID, Customer customer)
    {
        bool found = false;
        Artwork purchase;
        for (auto it = artworksForSale.begin(); it != artworksForSale.end(); it++)
        {
            if (it->getID() == artworkID)
            {
                found = true;
                purchase = *it;
                artworksForSale.erase(it);
                break;
            }
        }

        if (!found)
        {
            return;
        }

        Sale newSale;
        int customer_id = getCustomerID(customer.getName(), customer.getEmail());
        if (customer_id == -1)
        {
            addCustomer(customer);
        }

        newSale.setArtworkID(purchase.getID());
        newSale.setCustomerID(customer_id);
        newSale.setSaleDate(getTodaysDate());
        salesRecords.push_back(newSale);

    }

    void Gallery::addCuration(Curation curation)
    {
        curationsRecords.push_back(curation);
    }

    void Gallery::addSale(Sale sale)
    {
        salesRecords.push_back(sale);
    }


} //end of NS_ARTGALLERY
