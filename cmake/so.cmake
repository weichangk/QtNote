add_library(${PROJECT_NAME} SHARED
    ${MY_INC}
    ${MY_SRC}
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MY_FIND_2NDPARTY_PACK_LINK} ${MY_FIND_3RDPARTY_PACK_LINK})