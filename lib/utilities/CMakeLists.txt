set(UTILS "UTILS")

add_library(${UTILS} STATIC)

target_sources(${UTILS} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/queue/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/num/concatNum.c
)

target_include_directories(${UTILS} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/queue
    ${CMAKE_CURRENT_SOURCE_DIR}/num
)

target_compile_definitions(${UTILS} PRIVATE
)