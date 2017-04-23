#Compilation flags
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic" )

#Files to include
file( GLOB SOURCES *.h *.cpp )

#Target to build
add_executable( LinkedList ${SOURCES} )
