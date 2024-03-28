# CMakeList.txt : CMake project for vulnerable_website, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (vulnerable_website "vulnerable_website.cpp" "vulnerable_website.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET vulnerable_website PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
