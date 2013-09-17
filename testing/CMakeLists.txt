cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME testing)
project(${PROJECT_NAME})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(srcs
	main.cpp
	App.cpp
	Keyboard.cpp
	Mouse.cpp
	Camera.cpp
)

add_executable(${PROJECT_NAME} ${srcs})

find_library(GLUT_LIB glut)
find_library(GL_LIB GL)
find_library(GLU_LIB GLU)

target_link_libraries(${PROJECT_NAME}
	${GLUT_LIB}
	${GL_LIB}
	${GLU_LIB}
)
