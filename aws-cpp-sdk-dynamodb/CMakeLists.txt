cmake_minimum_required(VERSION 2.6)
project(aws-cpp-sdk-dynamodb)

  file(GLOB AWS_DYNAMODB_HEADERS
    "include/aws/dynamodb/*.h"
  )

  file(GLOB AWS_DYNAMODB_MODEL_HEADERS
    "include/aws/dynamodb/model/*.h"
  )

  file(GLOB AWS_DYNAMODB_SOURCE
    "source/*.cpp"
  )

  file(GLOB AWS_DYNAMODB_MODEL_SOURCE
    "source/model/*.cpp"
  )

  file(GLOB DYNAMODB_SRC
    ${AWS_DYNAMODB_HEADERS}
    ${AWS_DYNAMODB_MODEL_HEADERS}
    ${AWS_DYNAMODB_SOURCE}
    ${AWS_DYNAMODB_MODEL_SOURCE}
  )

  if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
      source_group("Header Files\\aws\\dynamodb" FILES ${AWS_DYNAMODB_HEADERS})
      source_group("Header Files\\aws\\dynamodb\\model" FILES ${AWS_DYNAMODB_MODEL_HEADERS})
      source_group("Source Files" FILES ${AWS_DYNAMODB_SOURCE})
      source_group("Source Files\\model" FILES ${AWS_DYNAMODB_MODEL_SOURCE})
    endif(MSVC)
  endif()

  set(DYNAMODB_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    "${CORE_DIR}/include/"
  )

  include_directories(${DYNAMODB_INCLUDES})

  if(MSVC AND BUILD_SHARED_LIBS)
    add_definitions("-DAWS_DYNAMODB_EXPORTS")
  endif()

  add_library(aws-cpp-sdk-dynamodb ${LIBTYPE} ${DYNAMODB_SRC})
  target_link_libraries(aws-cpp-sdk-dynamodb aws-cpp-sdk-core)
  list(APPEND AWS_INSTALLED_LIBS "aws-cpp-sdk-dynamodb")
  set(AWS_INSTALLED_LIBS "${AWS_INSTALLED_LIBS}" PARENT_SCOPE)

  if(NOT MSVC)
    add_definitions(-std=c++11)
  endif()

  #uncomment when unit tests are automatically generated
  #add_test(run${metadata.namespace}Tests run${metadata.namespace}Tests)

  install (TARGETS aws-cpp-sdk-dynamodb
           ARCHIVE DESTINATION ${ARCHIVE_DIRECTORY}/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME}
           LIBRARY DESTINATION lib/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME}
           RUNTIME DESTINATION bin/${SDK_INSTALL_BINARY_PREFIX}/\${CMAKE_INSTALL_CONFIG_NAME})

  install (FILES ${AWS_DYNAMODB_HEADERS} DESTINATION include/aws/dynamodb)
  install (FILES ${AWS_DYNAMODB_MODEL_HEADERS} DESTINATION include/aws/dynamodb/model)

