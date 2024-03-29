cmake_minimum_required (VERSION 3.8)

project ("vulnerable_website")

add_subdirectory(${PROJECT_SOURCE_DIR}/include/cpp-httplib)

set(SOURCES 
	${PROJECT_SOURCE_DIR}/src/vulnerable_website.cpp
	${PROJECT_SOURCE_DIR}/src/utils.cpp
	${PROJECT_SOURCE_DIR}/include/utils.h 
	${PROJECT_SOURCE_DIR}/include/vulnerable_website.h
)

add_executable(vulnerable_website ${SOURCES})

target_link_libraries(vulnerable_website httplib::httplib)
target_include_directories(vulnerable_website PRIVATE ${PROJECT_SOURCE_DIR}/include)



