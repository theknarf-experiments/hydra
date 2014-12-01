file(GLOB SRCS *.c)

find_package("curl" REQUIRED)
find_package("jansson" REQUIRED)

include_directories(${CURL_INCLUDE_DIR} ${JANSSON_INCLUDE_DIR})
link_libraries(${CURL_LIBRARY} ${JANSSON_LIBRARY})

add_executable (wpm ${SRCS})
