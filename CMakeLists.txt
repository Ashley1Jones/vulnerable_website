cmake_minimum_required (VERSION 3.8)

project ("vulnerable_website")

add_subdirectory(${PROJECT_SOURCE_DIR}/include/cpp-httplib)

set(SOURCES src/vulnerable_website.cpp)

add_executable(vulnerable_website ${SOURCES})

target_link_libraries(vulnerable_website httplib::httplib)

target_include_directories(
	vulnerable_website
	PRIVATE
		${PROJECT_SOURCE_DIR}/include
)

