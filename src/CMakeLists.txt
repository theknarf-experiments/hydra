file(GLOB SRCS *.c)

find_package("curl" REQUIRED)
find_package("jansson" REQUIRED)

add_executable (wpm
    install.c install.h
    list.c list.h
    wpm.c
settings.h)

target_include_directories(wpm PUBLIC
    ${CURL_INCLUDE_DIR}
    ${JANSSON_INCLUDE_DIR}
)
target_link_libraries(wpm
    ${CURL_LIBRARY}
    ${JANSSON_LIBRARIES}
)