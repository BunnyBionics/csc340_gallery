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

namespace NS_UTESTS{

using namespace NS_ARTGALLERY;

//class Artwork; a partial unit testing.
//write one unit test each for the following member functions of the Artwork class
//  . default constructor and accessors --->bool test_Artwork();
//  . setStyle() and getStyle()    --->bool test_set_getStyle_Artwork();
//  . setDimension(), getWidth(), getHeight() and getDepth() --->bool test_setDimension_Artwork();

//class Artist; a partial unit testing.
//write one unit test each for the following member functions of the Artist class
// .default constructor and accessors -->bool test_Artist();
// .setID() and getID()--->bool test_set_getID_Artist();


//class Customer; a partial unit testing.
//write one unit test each for the following member functions of the Customer class
// .the parameterized constructor and accessors -->bool test_Customer2();
// .setName() and getName()--->bool test_set_getName_Customer();


//class Curation; a partial unit testing.
//write one unit test each for the following member functions of the Curation class
// .the parameterized constructor and accessors -->bool test_Curation2();
// .setCurationDate() and getCurationDate()--->bool test_set_getDate_Curation();


//class Sale; a partial unit testing.
//write one unit test each for the following member functions of the Sale class
// .the parameterized constructor and accessors -->bool test_Sale2();
// .setCustomerID() and getCustomerID()--->bool test_set_getCustomerID_Sale();


//class Gallery; a partial unit testing.
//write one unit test for the Gallery::getArtistID() function correspoinding to either of the two scenarios: exist/doesn't exist
//  bool test_getArtistID_Gallery();

//write one unit test for the Gallery::getCustomerID() function, correspoinding to either of the two scenarios: exist/doesn't exist
//  bool test_getCustomerID_Gallery();

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty.
// bool test_getIDsOfArtistsForSale_Gallery();

//write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty. This test will call the curateArtwork() function.
// bool test_getIDsOfArtworksForSale_Gallery();


//write one unit test for the genArtworksReport() based on ArtType
//   bool test_genArtworksReport_artType_Gallery();


// Write one unit test for Gallery::curateArtwork().
//  bool test_curateArtwork_Gallery();

//write one unit test for the Gallery::sellArtwork() function
//  bool test_sellArtwork_Gallery();

}//end-of namespace NS_UTESTS
#endif