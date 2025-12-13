cmake_minimum_required(VERSION 4.0)
project(nvimSDL3 C)
set(CMAKE_C_STANDARD 11)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
	FetchContent_Declare(${libName}
		GIT_REPOSITORY 	${gitURL}
		GIT_TAG		${gitTag}
		GIT_SHALLOW	TRUE
		GIT_PROGRESS	TRUE
	)
	FetchContent_MakeAvailable(${libName})
endfunction()

find_package(SDL3 QUIET)
if (NOT SDL3_FOUND)
	message(STATUS "Cloning SDL3 git from GitHub")
	include_dependency(SDL3 https://github.com/libsdl-org/SDL.git release-3.2.18)
else()
	message(STATUS "Using local SDL3")
endif()

find_package(SDL3_ttf QUIET)
if (NOT SDL3_ttf_FOUND)
    message(STATUS "Cloning SDL3_TTF git from GitHub")
	include_dependency(SDL3_ttf https://github.com/libsdl-org/SDL_ttf.git release-3.2.2)
else()
	message(STATUS "Using local SDL3_ttf")
endif()

add_executable(nvimSDL3
	Source/main.c
	Source/game.c
	Source/init.c
	Source/utils.c
	Header/game.h
	Header/init.h
	Header/utils.h
)

target_compile_definitions(nvimSDL3 PRIVATE SDL_MAIN_USE_CALLBACKS)

target_link_libraries(nvimSDL3 PRIVATE
	SDL3::SDL3
)
