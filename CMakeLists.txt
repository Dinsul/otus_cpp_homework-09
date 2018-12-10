cmake_minimum_required(VERSION 3.2)
#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(range VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(range VERSION 0.0.0)
endif ()

include(${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
conan_set_find_library_paths()

include_directories("${Boost_INCLUDE_DIR} ${CONAN_INCLUDE_DIRS}")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.h")

add_executable(test_${PROJECT_NAME} "test_${PROJECT_NAME}.cpp" "${PROJECT_NAME}.cpp" "${PROJECT_NAME}.h")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
    INCLUDE_DIRECTORIES "${CONAN_INCLUDE_DIRS}"
    )

set_target_properties(test_${PROJECT_NAME} PROPERTIES
    COMPILE_DEFINITIONS ${CONAN_LIBS}
    INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIR} ${CONAN_INCLUDE_DIRS}"
    )

#target_link_libraries(${PROJECT_NAME}
#    ${CONAN_LIBS}
#    )

target_link_libraries(test_${PROJECT_NAME}
    ${CONAN_LIBS}
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
