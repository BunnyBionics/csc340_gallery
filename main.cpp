//
//  main.cpp
//  ArtGallerySimplified
//
//created by [your name]
//date: 

#include <iostream>
#include "util_date_uniqueIDs.h"
#include "unitTests.h"

//please feel free to create a text-based user interface to manage an art gallery 

int main()
{
    using namespace NS_ARTGALLERY;
    using namespace NS_UTESTS;

    cout << "Testing Artwork class\n";
    cout << "test_Artwork() " << (test_Artwork() ? "passed" : "failed") << endl;
    cout << "test_set_getStyle_Artwork() " << (test_set_getStyle_Artwork() ? "passed" : "failed") << endl;
    cout << "test_setDimension_Artwork() " << (test_setDimension_Artwork() ? "passed" : "failed") << endl << endl;

    cout << "Testing Artist class\n";
    cout << "test_Artist() " << (test_Artist() ? "passed" : "failed") << endl;
    cout << "test_set_getID_Artist() " << (test_set_getID_Artist() ? "passed" : "failed") << endl << endl;

    cout << "Testing Customer class\n";
    cout << "test_Customer2() " << (test_Customer2() ? "passed" : "failed") << endl;
    cout << "test_set_getName_Customer() " << (test_set_getName_Customer() ? "passed" : "failed") << endl << endl;

    cout << "Testing Curation class\n";
    cout << "test_Curation2() " << (test_Curation2() ? "passed" : "failed") << endl;
    cout << "test_set_getDate_Curation() " << (test_set_getDate_Curation() ? "passed" : "failed") << endl << endl;

    cout << "Testing Sale class\n";
    cout << "test_Sale2() " << (test_Sale2() ? "passed" : "failed") << endl;
    cout << "test_set_getCustomerID_Sale() " << (test_set_getCustomerID_Sale() ? "passed" : "failed") << endl << endl;

    cout << "Testing Gallery class\n";
    cout << "test_getArtistID_Gallery() " << (test_getArtistID_Gallery() ? "passed" : "failed") << endl;
    cout << "test_getCustomerID_Gallery() " << (test_getCustomerID_Gallery() ? "passed" : "failed") << endl;
    cout << "test_getIDsOfArtistsForSale_Gallery() " << (test_getIDsOfArtistsForSale_Gallery() ? "passed" : "failed") <<
        endl;
    cout << "test_getIDsOfArtworksForSale_Gallery() " << (test_getIDsOfArtworksForSale_Gallery() ? "passed" : "failed")
        << endl;
    cout << "test_genArtworksReport_artType_Gallery() " << (test_genArtworksReport_artType_Gallery() ? "passed" : "failed") << endl;
    cout << "test_curateArtwork_Gallery() " << (test_curateArtwork_Gallery() ? "passed" : "failed") << endl;
    cout << "test_sellArtwork_Gallery() " << (test_sellArtwork_Gallery() ? "passed" : "failed") << endl << endl;

    return 0;
}
