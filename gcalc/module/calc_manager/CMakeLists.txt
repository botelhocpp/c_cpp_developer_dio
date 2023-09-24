project(gcalc_module_calc_manager)

set(SOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(HEADERS_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

set(SOURCES
    ${SOURCES_DIR}/calc_manager.c
)
set(HEADERS
    ${HEADERS_DIR}/calc_manager.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINKER_LANGUAGE C
    C_STANDARD 11
)

target_include_directories(${PROJECT_NAME} PUBLIC ${GCALC_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    m
)
