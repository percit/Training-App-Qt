set(
  PROJECT_SOURCES
  main.cpp
  database.cpp
  DataBaseModel.cpp
  firebase_database.cpp
  firebase_auth.cpp
  NotificationClient.cpp
  ../qml/qml.qrc
)


if(ANDROID)
qt_add_executable(
  Training-app
  ${PROJECT_SOURCES}
  # NotificationClient.java
)
else()
add_executable(
  Training-app
  ${PROJECT_SOURCES}
)
endif()

set_target_properties(Training-app PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)


target_compile_definitions( #nie wiem czy to jest potrzebne
  Training-app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(
  Training-app
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
  Qt${QT_VERSION_MAJOR}::Core5Compat
)

# install(TARGETS Training-app
#     RUNTIME DESTINATION "destination"
#     BUNDLE DESTINATION "destination"
#     LIBRARY DESTINATION "destination"
# )
