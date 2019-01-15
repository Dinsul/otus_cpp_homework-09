cmake_minimum_required(VERSION 3.2)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(range VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(range VERSION 0.0.0)
endif ()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_libraries("${CONAN_LIBS}")
include_directories("${CONAN_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} "main.cpp" "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.h")

add_executable(test_${PROJECT_NAME} "test_${PROJECT_NAME}.cpp" "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.h")

set_target_properties(${PROJECT_NAME} test_${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
    )

set_target_properties(test_${PROJECT_NAME} PROPERTIES
    COMPILE_OPTIONS "-D_GLIBCXX_USE_CXX11_ABI=0"
    )

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dinsul2.0@gmail.com)

include (CPack)

enable_testing()

add_test(test_split "test_${PROJECT_NAME}")
