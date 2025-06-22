project('nlang', 'c')

utils = declare_dependency(
  include_directories: ['src/utils']
)

parser = declare_dependency(
  include_directories: ['src/parser', 'src']
)

executable('testexe', 'src/main.c', dependencies: [parser])
