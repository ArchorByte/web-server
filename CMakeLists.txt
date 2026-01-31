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

if (WIN32)
    set(WS2_LIB ${CMAKE_SOURCE_DIR}/bin/windows/lib/WS2_32.Lib)

    add_custom_target(copy_binaries ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/windows/dll/ws2_32.dll" "${CMAKE_SOURCE_DIR}/build/win64/out"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/windows/dll/libgcc_s_seh-1.dll" "${CMAKE_SOURCE_DIR}/build/win64/out"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/windows/dll/libstdc++-6.dll" "${CMAKE_SOURCE_DIR}/build/win64/out"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/windows/dll/libwinpthread-1.dll" "${CMAKE_SOURCE_DIR}/build/win64/out"
    )

    target_link_libraries(web_server PRIVATE ${WS2_LIB})
else()
    add_custom_target(copy_binaries ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/linux/libgcc_s-15-20251211.so.1" "${CMAKE_SOURCE_DIR}/build/linux/out/libgcc_s-15-20251211.so.1"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/linux/libpthread.so.0" "${CMAKE_SOURCE_DIR}/build/linux/out/libpthread.so.0"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/bin/linux/libstdc++.so.6.0.34" "${CMAKE_SOURCE_DIR}/build/linux/out/libstdc++.so.6.0.34"
    )
endif()
