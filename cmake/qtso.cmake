qt_add_library(${PROJECT_NAME} SHARED
    ${MY_QRC}
    ${MY_INC}
    ${MY_SRC}
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MY_FIND_QT_PACK_LINK})