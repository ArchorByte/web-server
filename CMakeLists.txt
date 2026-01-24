cmake_minimum_required(VERSION 3.10)
project(web_server)
set(CMAKE_CXX_STANDARD 17)

include_directories (
    ${CMAKE_SOURCE_DIR}/src/routes
    ${CMAKE_SOURCE_DIR}/src/routes/pages
    ${CMAKE_SOURCE_DIR}/src/socket
    ${CMAKE_SOURCE_DIR}/src/utils/files
    ${CMAKE_SOURCE_DIR}/src/utils/parsers
    ${CMAKE_SOURCE_DIR}/src/utils/text
)

file(GLOB MAIN main.cpp)
file(GLOB ROUTES src/routes/*.cpp)
file(GLOB ROUTES_PAGES src/routes/pages/*.cpp)
file(GLOB SOCKET src/socket/*.cpp)
file(GLOB UTILS_FILES src/utils/files/*.cpp)
file(GLOB UTILS_PARSERS src/utils/parsers/*.cpp)
file(GLOB UTILS_TEXT src/utils/text/*.cpp)

set(ALL_SOURCES
    ${MAIN}
    ${ROUTES}
    ${ROUTES_PAGES}
    ${SOCKET}
    ${UTILS_FILES}
    ${UTILS_PARSERS}
    ${UTILS_TEXT}
)

add_executable(web_server ${ALL_SOURCES})
