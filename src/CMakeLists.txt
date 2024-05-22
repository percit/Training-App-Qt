set(
  PROJECT_SOURCES
  main.cpp
  database.cpp
  DataBaseModel.cpp
  firebase_database.cpp
  firebase_auth.cpp
  ../qml/qml.qrc
)

if(ANDROID)
add_library(
  Training-app SHARED
  ${PROJECT_SOURCES}
)
else()
add_executable(
  Training-app
  ${PROJECT_SOURCES}
)
endif()


target_compile_definitions(
  Training-app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(
  Training-app
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
  Qt${QT_VERSION_MAJOR}::Core5Compat
)