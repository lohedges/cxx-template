IF(DOXYGEN)
    IF(DOXYGEN_DOT_PATH)
        SET(DOXYGEN_HAVE_DOT "YES")
    ELSE(DOXYGEN_DOT_PATH)
        SET(DOXYGEN_HAVE_DOT "NO")
    ENDIF(DOXYGEN_DOT_PATH)

    # Configure the doxygen file
    CONFIGURE_FILE (${SHAPES_SOURCE_DIR}/dox/Doxyfile.in ${SHAPES_BINARY_DIR}/dox/Doxyfile)

    ADD_CUSTOM_COMMAND (OUTPUT ${SHAPES_BINARY_DIR}/doc/html/index.html
                        COMMAND ${DOXYGEN} ${SHAPES_BINARY_DIR}/dox/Doxyfile
                        DEPENDS ${SHAPES_SOURCE_DIR}/dox/*.dox
                                ${SHAPES_SOURCE_DIR}/src/*.h
                                ${SHAPES_SOURCE_DIR}/src/*.cpp
                                ${SHAPES_SOURCE_DIR}/dox/Doxyfile.in)

    ADD_CUSTOM_TARGET (doc DEPENDS ${SHAPES_BINARY_DIR}/doc/html/index.html)
ENDIF (DOXYGEN)
