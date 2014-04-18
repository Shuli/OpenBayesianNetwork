CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT("Open Bayesian Network" CXX)

SET(PJ_VERSION "1.0.0")
SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_C_FLAGS_RELEASE "-Wall -O2")
SET(CMAKE_C_FLAGS_DEBUG "-g")

SET(Boost_USE_STATIC_LIBS OFF) 
SET(Boost_USE_MULTITHREADED ON)  
SET(Boost_USE_STATIC_RUNTIME OFF) 

FIND_PACKAGE(Boost COMPONENTS system filesystem program_options regex signals thread iostreams date_time python) 

IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS}) 
ENDIF()

SET(SOURCES
Probability.cpp
ProbabilityComposite.cpp
ProbabilityNode.cpp
ProbabilityTest.cpp
)

SET(HEADERS
Probability.h
ProbabilityComposite.h
ProbabilityNode.h
)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
LINK_DIRECTORIES(${PROJECT_LIBRARY_DIR})

ADD_EXECUTABLE(Bayesian ${SOURCES})

