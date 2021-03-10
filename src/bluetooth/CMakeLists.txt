zephyr_include_directories(services)
target_sources(app PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/gap_peripheral.c
${CMAKE_CURRENT_SOURCE_DIR}/gap_peripheral.h
${CMAKE_CURRENT_SOURCE_DIR}/services/custom_service.c
${CMAKE_CURRENT_SOURCE_DIR}/services/custom_service.h
)