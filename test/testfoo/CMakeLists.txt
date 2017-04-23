file(GLOB SRCS *.h *.cpp )

ADD_EXECUTABLE(testfoo ${SRCS})

TARGET_LINK_LIBRARIES(testfoo
    libgtest
    libgmock
)

add_test(NAME testfoo
         COMMAND testfoo)