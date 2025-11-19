cmake_minimum_required(VERSION 4.0)
project(gallery)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(gallery
        Artwork_Artist.cpp
        Artwork_Artist.h
        Customer_Curation_Sale_Gallery.cpp
        Customer_Curation_Sale_Gallery.h
        DesignDoc.h
        main.cpp
        unitTests.h
        util_date_uniqueIDs.cpp
        util_date_uniqueIDs.h)
