/*

 Your to-do #1:  describe your algorithm in pseudo code for the following data
 operation in the Gallery class:
    - curateArtwork(Artwork newItem, Artist artist); //artwork curation: curate
 a new piece of artwork for the gallery. newItem.ID and artist.ID are set to -1
 (not available) initially. As a result, you’ll need to assign this newItem a
 unique ID. Check if the artist is already on the artistList using their name
 and email. If new, assign this artist a unique ID and add them to the
 artistList. if not new, retrieve their ID from the artistList. You will also
 need to update the artworkListCurated and the artworkListForSale. Finally, you
 will need to update the curationRecords to include this new curation.

NS_ARTGALLERY::curateArtwork(Artwork newItem, Artist artist);
A new Curation is created for the artwork
assign a unique ID to the Artwork
The Artwork is added to the list of artworksCurated
The Artwork is added to the list of artworksForSale
assign the new Artwork ID to the Curation's Artwork ID
If the Artist isn't on artistList using name and email:
    assign a unique ID to the Artist
    add the Artist to artistList
else
    retrieve the existing Artist's ID
assign the Artist's ID to Curation's Artist ID
create a new Date object with today's Date
assign the Date to the Curation
add the Curation to curationsRecords

 Your to-do #2:  describe your algorithm in pseudo code for the following data
 operation in the Gallery class:
    - sellArtwork(int artworkID, Customer customer); //artwork sale: sell a
 for-sale artwork to a customer. customer.ID is set to -1 initially. So you will
 need to find out if this customer is new or not using their name and email
 address. If new, assign this customer a unique ID and add them to the
 customerList. If not, retrieve their ID from customerList. You will also need
 to check if the specified artworkID is still for sale. If yes, update the
 artworkListForSale by removing this artwork that was just sold, and update the
 salesRecords to include this new sale.


NS_ARTGALLERY::sellArtwork(int artworkID, Customer customer);
if Artwork isn't in artworksForSale:
    return
else:
    remove Artwork from artworksForSale
create a Sale
if Customer isn't on customerList by name and email:
    assign a unique ID to the Customer
    add Customer to customerList
else
    retrieve Customer's ID
assign Customer's ID to the Sale's customer ID
assign Artwork's ID to Sale's artwork ID
create a Date with today's date and assign to Sale's date
add Sale to salesRecords

Your to-do #3:  describe your algorithm in pseudo code for the following data
 operation in the Gallery class:
     - genArtworksReport( ReportType reportType); //summarize a gallery's
 curated artworks by their type, style, and subject. ReportType is an enum class
 that consists of {artType, artStyle, artSubject}.  For example, if reportType
 is ReportType::artType, your summary will consist of the following pairs:
 (ArtType::painting, #), (ArtType::photography, #), (ArtType::drawing, #),
 (ArtType::sculpture, #), (ArtType::other, #). Here, ArtType is another
 user-defined enum class. You algorithm is going to replace the # with the
 actual number of artworks of the corresponding artType.

NS_ARTGALLERY::genArtworksReport(ReportType reportType);
create a vector to hold the pairs of {category, quantity}
if reportType is artType:
    for (ArtType medium of [painting, photography, drawing, sculpture, other]):
        create Pair{medium, count_if(artsCurated, art.medium == medium)}
        add Pair to report vector
else if reportType is artStyle:
    for (ArtStyle art_style of [fineArt, abstract, modern, popArt, other]):
        create Pair{art_style, count_if(artsCurated, art.style == art_style)}
        add Pair to report vector
else if reportType is artSubject:
    for (ArtSubject art_subject of [nature, portrait, animal, cartoon, other]):
        create Pair{art_subject, count_if(artsCurated, art.subject == art_subject)}
        add Pair to report vector
return report vector

*/
#pragma once
