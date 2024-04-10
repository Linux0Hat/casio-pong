# Configure with [fxsdk build-fx] or [fxsdk build-cg], which provide the
# toolchain file and module path of the fxSDK

cmake_minimum_required(VERSION 3.15)
project(MyAddin)

include(GenerateG1A)
include(GenerateG3A)
include(Fxconv)
find_package(Gint 2.9 REQUIRED)

if("${FXSDK_PLATFORM_LONG}" STREQUAL fx9860G)
  set(SOURCES
    src-fx/main.c
    # ...
  )
  # Shared assets, fx-9860G-only assets and fx-CG-50-only assets
  set(ASSETS
    # ...
  )
  set(ASSETS_fx
    assets-fx/example.png
    # ...
  )

  fxconv_declare_assets(${ASSETS} ${ASSETS_fx} ${ASSETS_cg} WITH_METADATA)

  add_executable(myaddin-fx ${SOURCES} ${ASSETS} ${ASSETS_${FXSDK_PLATFORM}})
  target_compile_options(myaddin-fx PRIVATE -Wall -Wextra -Os)
  target_link_libraries(myaddin-fx Gint::Gint)
  generate_g1a(TARGET myaddin-fx OUTPUT "Pong.g1a"
    NAME "Pong" ICON assets-fx/icon.png)
elseif("${FXSDK_PLATFORM_LONG}" STREQUAL fxCG50)
  set(SOURCES
    src/main.c
    # ...
  )
  # Shared assets, fx-9860G-only assets and fx-CG-50-only assets
  set(ASSETS
    # ...
  )
  set(ASSETS_cg
    assets-cg/example.png
    # ...
  )

  fxconv_declare_assets(${ASSETS} ${ASSETS_fx} ${ASSETS_cg} WITH_METADATA)

  add_executable(myaddin ${SOURCES} ${ASSETS} ${ASSETS_${FXSDK_PLATFORM}})
  target_compile_options(myaddin PRIVATE -Wall -Wextra -Os)
  target_link_libraries(myaddin Gint::Gint)
  generate_g3a(TARGET myaddin OUTPUT "Pong.g3a"
    NAME "Pong" ICONS assets-cg/icon-uns.png assets-cg/icon-sel.png)
endif()
