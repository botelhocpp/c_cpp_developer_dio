project(gcalc_app)

set(SOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

set(SOURCES
    ${SOURCES_DIR}/signals_callbacks.c
    ${SOURCES_DIR}/main.c
)

set(GCALC_EXECUTABLE gcalc)

add_executable(${GCALC_EXECUTABLE} ${SOURCES} ${HEADERS})

target_include_directories(${GCALC_EXECUTABLE} PUBLIC ${GCALC_DIR})

target_link_libraries(${GCALC_EXECUTABLE} PUBLIC
    ${GTK_LIBRARIES}
)

target_link_libraries(${GCALC_EXECUTABLE} PRIVATE
    gcalc_view
    gcalc_module_calc_manager
)

add_custom_command(TARGET ${GCALC_EXECUTABLE} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${GCALC_DIR}/view/model ${CMAKE_BINARY_DIR}/bin/model
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${GCALC_DIR}/view/static ${CMAKE_BINARY_DIR}/bin/static
)