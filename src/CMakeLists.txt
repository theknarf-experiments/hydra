file(GLOB SRCS *.c)

find_package("curl" REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
link_libraries(${CURL_LIBRARY})

add_executable (wpm ${SRCS})
