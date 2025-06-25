project('nlang', 'c', default_options: ['c_std=c99'])

if get_option('buildtype').startswith('debug')
  add_project_arguments(['-g3'], language: 'c')
  add_project_arguments(['-Ddebug'], language: 'c')
endif

# utils = declare_dependency(
#   include_directories: ['src/utils']
# )
#
# parser = declare_dependency(
#   include_directories: ['src/parser']
# )

executable(
  'testexe', [
    'src/main.c',
    'src/parser/tokenizer.c',
    'src/utils/parser_reading.c',
  ],
  include_directories: ['src/'],
  # dependencies: [parser]
)
