cmake_minimum_required(VERSION 3.14)
project(My_ERP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FS")
# add_compile_options(/FS)

# Qt 라이브러리 설정
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

# MOC 처리 추가 (자동 생성 코드)
set(CMAKE_AUTOMOC ON)

# 소스 파일 추가
add_executable(My_ERP 
    ./src/main.cpp 
    ./src/Database/DatabaseManager.cpp
    ./src/Database/ClientDatabaseManager.cpp
    ./src/Database/OrderDatabaseManager.cpp
    ./src/Views/MainWindow.cpp
    ./src/Views/OrderWindow.cpp
    ./src/Views/ClientWindow.cpp
    ./src/Views/ClientRegisterDialog.cpp
    ./src/Views/FabricInventoryWindow.cpp
    ./src/Views/WoodInventoryWindow.cpp
    ./src/Views/AngleInventoryWindow.cpp
)

# Qt 라이브러리 연결
target_link_libraries(My_ERP 
    Qt6::Core 
    Qt6::Sql
    Qt6::Widgets
)