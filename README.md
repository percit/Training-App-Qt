# Training-App-Qt

This is a multiplatform Running app build with MVVM pattern

Technology stack:

1. C++ - backend
2. Qt Quick - app GUI
3. Mapbox/OpenStreetView - creating a map, getting GPS data, drawing routes, getting data from routes such as distance and so on
4. SQLite - local database
5. Android SDK - deployment on mobile
6. GTest - testing
7. CMake - build automation



TODO:
1. Email Authentication via Firebase
2. Database on Firebase
3. Fix Tests


How to go from Desktop/Android:

Clean->Run CMake->Build->Compile (don't skip even one step)

Commit c2945c71274c5eafb9bae044a8eb4130bf1aae9a is last one working on desktop and android and has no firebase

![Getting Started](images/map-image.png)
![Getting Started](images/progress-image.png)
![Getting Started](images/stats-image.png)