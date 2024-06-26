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

add_library(database_lib
  STATIC
  database.cpp
  DataBaseModel.cpp
)
target_link_libraries(
  database_lib
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Sql
)

if(ANDROID)
  qt_standard_project_setup()
  qt_add_executable(
    Training-app
    ${PROJECT_SOURCES}
    android/src/org/qtproject/example/androidnotifier/NotificationClient.java
    android/AndroidManifest.xml
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
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Sql
  Qt${QT_VERSION_MAJOR}::Core5Compat
  Qt${QT_VERSION_MAJOR}::CorePrivate # for notifications
)

if(ANDROID)
  set_property(TARGET Training-app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
            ${CMAKE_CURRENT_SOURCE_DIR}/android)
  qt_finalize_executable(Training-app)
endif()


set(training_app_resource_files
    "../qml/MainScreen.qml"
    "../qml/Helper.js"
    "../qml/Style.qml"
    "../qml/pages/AchievementsPage.qml"
    "../qml/pages/RunningPage.qml"
    "../qml/pages/WeeklyStatsPage.qml"
    "../qml/pages/SettingsPage.qml"
    "../qml/pages/LogPage.qml"
    "../qml/pages/DebugPage.qml"
    "../qml/utils/BottomRow.qml"
    "../qml/utils/MainPage.qml"
    "../qml/utils/MenuButton.qml"
    "../qml/utils/ProgresBar.qml"
    "../qml/utils/TextButton.qml"
    "../qml/utils/TextWithIcon.qml"
    "../qml/utils/RadialProgressBar.qml"
    "../qml/utils/SettingsItem.qml"
    "../qml/utils/StyledComboBox.qml"
    "../qml/utils/CustomIcon.qml"
    "../qml/viewmodels/DataBaseViewModel.qml"
    "../qml/viewmodels/MapModel.qml"
    "../qml/assets/achievement.png"
    "../qml/assets/person.png"
    "../qml/assets/route.png"
    "../qml/assets/run.png"
    "../qml/assets/settings.png"
    "../qml/assets/shoe-sneaker.png"
    "../qml/assets/speed.png"
    "../qml/assets/star.png"
    "../qml/assets/tasks.png"
    "../qml/assets/time.png"
    "../qml/assets/timer.png"
    "../qml/assets/menu.png"
    "../qml/assets/close.png"
)

qt_add_resources(Training-app "Training-app"
    PREFIX
        "destination"
    FILES
        ${trainng_app_resource_files}
)

install(TARGETS Training-app
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
) # this is needed for installing with qt creator
