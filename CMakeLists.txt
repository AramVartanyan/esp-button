set(COMPONENT_ADD_INCLUDEDIRS .)

# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS ./button.c ./port.c ./toggle.c)

register_component()
target_compile_options(${COMPONENT_LIB} PRIVATE -DESP_IDF)
