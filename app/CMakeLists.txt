add_executable(${EXE_NAME})

set(CTRL "src/controllers")
set(SRVC "src/services")
set(DRV "src/drivers")
set(CORE "lib/${MCU}/core/src")

target_sources(${EXE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${CTRL}/mainCtrl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${CTRL}/sensorCtrl.c

    ${CMAKE_CURRENT_SOURCE_DIR}/${DRV}/usartDrv.c

    ${CMAKE_CURRENT_SOURCE_DIR}/${SRVC}/TF1012Srvc.c

    ${PROJECT_SOURCE_DIR}/${CORE}/freertos.c
    ${PROJECT_SOURCE_DIR}/${CORE}/startup_stm32f103c8tx.s
    ${PROJECT_SOURCE_DIR}/${CORE}/stm32f1xx_hal_timebase_tim.c
    ${PROJECT_SOURCE_DIR}/${CORE}/stm32f1xx_it.c
    ${PROJECT_SOURCE_DIR}/${CORE}/syscalls.c
    ${PROJECT_SOURCE_DIR}/${CORE}/sysmem.c
    ${PROJECT_SOURCE_DIR}/${CORE}/system_stm32f1xx.c
)

target_include_directories(${EXE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/services
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/drivers
    ${CMAKE_BINARY_DIR}/config_files/include
)

target_link_options(${EXE_NAME} PRIVATE
    -T${PROJECT_SOURCE_DIR}/${CORE}/${LINKER_SCRIPT}
    ${RUNTIME_LIBRARY}
    ${RUNTIME_LIBRARY_SYSCALLS}
    -Wl,--print-memory-usage
    -Wl,-Map=${PROJECT_NAME}.map
    -Wl,--gc-sections
    -static
    -Wl,--start-group
    -lc
    -lm
    -Wl,--end-group
)

target_link_libraries(${EXE_NAME} PRIVATE
    ${MCU}_HAL
    freertos_kernel
    freertos_config
    UTILS
)

target_compile_definitions(${EXE_NAME} PRIVATE
    ${MCU}
    USE_HAL_DRIVER
)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${EXE_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

add_custom_command(
    TARGET ${EXE_NAME}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${EXE_NAME} ${PROJECT_NAME}.bin
)
