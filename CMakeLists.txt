cmake_minimum_required(VERSION 3.16)

project(central_alertas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CENTRAL_ALERTAS_SOURCES
    alerta.cpp
    central.cpp
    alertas/alerta_critico.cpp
    alertas/alerta_aviso.cpp
    alertas/alerta_info.cpp
    alertas/alerta_debug.cpp
)

add_executable(central_alertas
    main.cpp
    ${CENTRAL_ALERTAS_SOURCES}
)

target_include_directories(central_alertas PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(central_alertas_tests
    tests/test_alertas.cpp
    ${CENTRAL_ALERTAS_SOURCES}
)

target_include_directories(central_alertas_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(central_alertas PRIVATE -Wall -Wextra)
    target_compile_options(central_alertas_tests PRIVATE -Wall -Wextra)

    if(NOT MINGW)
        target_compile_options(central_alertas PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )
        target_link_options(central_alertas PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )

        target_compile_options(central_alertas_tests PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )
        target_link_options(central_alertas_tests PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined>
        )
    endif()
elseif(MSVC)
    target_compile_options(central_alertas PRIVATE /W4)
    target_compile_options(central_alertas_tests PRIVATE /W4)
endif()

enable_testing()
add_test(NAME central_alertas_tests COMMAND central_alertas_tests)
