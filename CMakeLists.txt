cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( loadDisplaySave src/chapter1/loadDisplaySave.cpp )
add_executable( mat src/chapter1/mat.cpp )
add_executable( logo src/chapter1/logo.cpp )

target_link_libraries( loadDisplaySave ${OpenCV_LIBS} )
target_link_libraries( mat ${OpenCV_LIBS} )
target_link_libraries( logo ${OpenCV_LIBS} )

# copy required images to every directory with executable
SET (IMAGES ${CMAKE_SOURCE_DIR}/images/puppy.bmp ${CMAKE_SOURCE_DIR}/images/smalllogo.png)
FILE(COPY ${IMAGES} DESTINATION .)
FILE(COPY ${IMAGES} DESTINATION "Debug")
FILE(COPY ${IMAGES} DESTINATION "Release")
