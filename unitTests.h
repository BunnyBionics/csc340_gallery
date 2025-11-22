//
//  unitTests.h
//  ArtGallerySimplified
//
//unit-test a few member functions for each class
//
//  Created by Hui Yang on 3/23/22.
//

#ifndef unitTests_h
#define unitTests_h

#include "Artwork_Artist.h"
#include "Customer_Curation_Sale_Gallery.h"

namespace NS_UTESTS
{
    using namespace NS_ARTGALLERY;

    //class Artwork; a partial unit testing.
    //write one unit test each for the following member functions of the Artwork class
    //  . default constructor and accessors --->bool test_Artwork();
    //  . setStyle() and getStyle()    --->bool test_set_getStyle_Artwork();
    //  . setDimension(), getWidth(), getHeight() and getDepth() --->bool test_setDimension_Artwork();

    bool test_Artwork()
    {
        Artwork work;
        return (work.getID() == -1 && work.getType() == ArtType::painting);
    }

    bool test_set_getStyle_Artwork()
    {
        Artwork work;
        if (work.getStyle() != ArtStyle::fineArt) return false;
        work.setStyle(ArtStyle::modern);
        if (work.getStyle() != ArtStyle::modern) return false;
        return true;
    }

    bool test_setDimension_Artwork()
    {
        Artwork work;
        work.setDimension(1.11, 2.22, 3.33);
        return (work.getWidth() == 1.11 && work.getHeight() == 2.22 && work.getDepth() == 3.33);
    }

    //class Artist; a partial unit testing.
    //write one unit test each for the following member functions of the Artist class
    // .default constructor and accessors -->bool test_Artist();
    // .setID() and getID()--->bool test_set_getID_Artist();

    bool test_Artist()
    {
        Artist artist;
        return (artist.getBirthYear() == 1900 && artist.getBirthPlace() == "na");
    }

    bool test_set_getID_Artist()
    {
        Artist artist;
        if (artist.getID() != -1) return false;
        artist.setID(667);
        if (artist.getID() != 667) return false;
        return true;
    }

    //class Customer; a partial unit testing.
    //write one unit test each for the following member functions of the Customer class
    // .the parameterized constructor and accessors -->bool test_Customer2();
    // .setName() and getName()--->bool test_set_getName_Customer();

    bool test_Customer2()
    {
        Customer customer(123, "anon", "asdf@gmail.com", "1300 Pennsylvania Ave.");
        return (customer.getID() == 123 && customer.getName() == "anon" && customer.getEmail() == "asdf@gmail.com" &&
            customer.getAddress() == "1300 Pennsylvania Ave.");
    }

    bool test_set_getName_Customer()
    {
        Customer customer;
        if (customer.getName() != "na") return false;
        customer.setName("named");
        if (customer.getName() != "named") return false;
        return true;
    }

    //class Curation; a partial unit testing.
    //write one unit test each for the following member functions of the Curation class
    // .the parameterized constructor and accessors -->bool test_Curation2();
    // .setCurationDate() and getCurationDate()--->bool test_set_getDate_Curation();

    bool test_Curation2()
    {
        Curation curation = Curation(123, 456, Date{5, 5, 5555});
        return (curation.getArtworkID() == 123 && curation.getArtistID() == 456 && curation.getCurationDate() ==
            Date(5, 5, 5555));
    }

    bool test_set_getDate_Curation()
    {
        Curation curation;
        if (curation.getCurationDate() != Date{1, 1, 2022}) return false;
        curation.setCurationDate(Date{4, 4, 4444});
        if (curation.getCurationDate() != Date{4, 4, 4444}) return false;
        return true;
    }

    //class Sale; a partial unit testing.
    //write one unit test each for the following member functions of the Sale class
    // .the parameterized constructor and accessors -->bool test_Sale2();
    // .setCustomerID() and getCustomerID()--->bool test_set_getCustomerID_Sale();

    bool test_Sale2()
    {
        Sale sale = Sale(123, 456, Date{3, 3, 3333});
        return (sale.getCustomerID() == 123 && sale.getArtworkID() == 456 && sale.getSaleDate() == Date(3, 3, 3333));
    }

    bool test_set_getCustomerID_Sale()
    {
        Sale sale;
        if (sale.getCustomerID() != -1) return false;
        sale.setCustomerID(987);
        if (sale.getCustomerID() != 987) return false;
        return true;
    }

    //class Gallery; a partial unit testing.
    //write one unit test for the Gallery::getArtistID() function correspoinding to either of the two scenarios: exist/doesn't exist
    //  bool test_getArtistID_Gallery();

    // test if artist does exist
    bool test_getArtistID_Gallery()
    {
        Gallery gal;
        Artist arty;
        arty.setName("Anubis");
        arty.setEmail("anubis@gmail.com");
        gal.addArtist(arty);
        int result = gal.getArtistID("Anubis", "anubis@gmail.com");
        return result == 1;
    }

    //write one unit test for the Gallery::getCustomerID() function, correspoinding to either of the two scenarios: exist/doesn't exist
    //  bool test_getCustomerID_Gallery();

    // testing when customer does exist
    bool test_getCustomerID_Gallery()
    {
        Gallery gal;
        Customer cust;
        cust.setName("Osiris");
        cust.setEmail("osiris@gmail.com");
        gal.addCustomer(cust);
        int result = gal.getCustomerID("Osiris", "osiris@gmail.com");
        return result == 1;
    }

    //write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty.
    // bool test_getIDsOfArtistsForSale_Gallery();

    bool test_getIDsOfArtistsForSale_Gallery()
    {
        Gallery gal;
        Artwork work;
        Artist arty;
        arty.setName("Nut");
        gal.curateArtwork(work, arty);
        Artwork work2;
        Artist arty2;
        arty2.setName("Tefnut");
        gal.curateArtwork(work2, arty2);
        Artwork work3;
        gal.curateArtwork(work3, arty2);
        // this has added three artworks and two artists
        return (gal.getIDsOfArtistsForSale().size() == 2 && gal.num_artists() == 2);
    }

    //write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty. This test will call the curateArtwork() function.
    // bool test_getIDsOfArtworksForSale_Gallery();

    bool test_getIDsOfArtworksForSale_Gallery()
    {
        Gallery gal;
        Artwork work;
        Artist arty;
        arty.setName("Ra");
        gal.curateArtwork(work, arty);
        Artwork work2;
        Artist arty2;
        arty2.setName("Horus");
        gal.curateArtwork(work2, arty2);
        Artwork work3;
        gal.curateArtwork(work3, arty2);
        // this has added three artworks and two artists
        return (gal.getIDsOfArtworksForSale().size() == 3 && gal.num_curations() == 3);
    }

    //write one unit test for the genArtworksReport() based on ArtType
    //   bool test_genArtworksReport_artType_Gallery();

    bool test_genArtworksReport_artType_Gallery()
    {
        Gallery gal;
        Artwork work;
        work.setType(ArtType::drawing);
        Artist arty;
        arty.setName("Thoth");
        gal.curateArtwork(work, arty);
        Artwork work2;
        work2.setType(ArtType::sculpture);
        Artist arty2;
        arty2.setName("Bastet");
        gal.curateArtwork(work2, arty2);
        Artwork work3;
        work3.setType(ArtType::sculpture);
        gal.curateArtwork(work3, arty2);
        auto report = gal.genArtworksReport(ReportType::artType);
        return (report.at(2).first == "ArtType::drawing"
            && report.at(2).second == 1
            && report.at(3).first == "ArtType::sculpture"
            && report.at(3).second == 2);
    }

    // Write one unit test for Gallery::curateArtwork().
    //  bool test_curateArtwork_Gallery();

    bool test_curateArtwork_Gallery()
    {
        Gallery gal;
        Artwork work;
        Artist arty;
        arty.setName("Sehkmet");
        gal.curateArtwork(work, arty);
        Artwork work2;
        gal.curateArtwork(work2, arty);
        return (gal.num_artists() == 1 && gal.num_curations() == 2);
    }

    //write one unit test for the Gallery::sellArtwork() function
    //  bool test_sellArtwork_Gallery();

    bool test_sellArtwork_Gallery()
    {
        Gallery gal;
        Artwork work;
        Artist arty;
        arty.setName("Ptah");
        gal.curateArtwork(work, arty);
        Customer customer;
        gal.sellArtwork(gal.getIDsOfArtworksForSale()[0], customer);
        return (gal.getIDsOfArtworksForSale().empty());
    }


} //end-of namespace NS_UTESTS
#endif
