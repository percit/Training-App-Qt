# Training-App-Qt

This is a multiplatform Running app build with MVVM pattern

# Technology stack:

1. C++ - backend
2. Qt Quick - app GUI
3. Mapbox/OpenStreetView - creating a map, getting GPS data, drawing routes, getting data from routes such as distance and so on
4. SQLite - local database
5. Android SDK - deployment on mobile
6. GTest - testing
7. CMake - build automation


# Running app:

In SETUP.md there is a tutorial how to set it up

Clean->Run CMake->Build->Compile (sometimes just compile doesn't work, so you have to click build first)

# Running tests:

For now, just comment out the main and uncomment catch_main.cpp, then "cmake .. && make -j16 && ./Training_App

In the future there will be a cmake flag for this to change from testing to normal

Commit c2945c71274c5eafb9bae044a8eb4130bf1aae9a is last one working on desktop and android and has no firebase, this should be fixed with a flag, or design pattern

![Getting Started](images/map-image.png)
![Getting Started](images/progress-image.png)
![Getting Started](images/stats-image.png)
